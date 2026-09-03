<h1 align="center">push_swap</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Shell-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white" alt="Shell"/>
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux"/>
  <img src="https://img.shields.io/badge/GNU%20Make-A42E2B?style=for-the-badge&logo=gnu&logoColor=white" alt="GNU Make"/>
</p>

<p align="center"><strong>Sorting with two stacks and eleven instructions, where the output is the list of moves and the score is its length.</strong></p>

---

## 📌 Overview

push_swap does not ask for a sorted list. It asks for the instructions that would produce one. The data sits in two stacks, only eleven moves are legal (push one element across, swap the top two, rotate a stack by one), and the program prints the sequence it would apply, which a separate checker then replays to see whether the numbers come out in order. So correctness is only the first half of the exercise: the sequence is also counted, and a solution that sorts perfectly in twice as many moves as the next one is simply worse.

That changes what the code has to be good at. There is no random access and no comparison operator on the output side, only moves whose cost is one line each, and a move is wasted the moment it undoes another or duplicates work the other stack was already doing. This implementation sorts by recursively splitting each half around a pivot between the two stacks, then does something the algorithm alone does not: it stops printing moves as it makes them. Operations are queued per stack, cancelling pairs are removed, and the two queues are interleaved so that a rotation on `a` lands next to a rotation on `b` and the pair collapses into one `rr`.

Measured with the benchmark script in this repo, that lands at roughly 664 moves for 100 random numbers and 5,070 for 500, against the two thresholds the project is graded on, 700 and 5,500.

## 🎯 Objectives

- Design a sorting method for a machine that has two stacks and no other primitive, and pay for every operation.
- Treat the move sequence as data to be optimised after the fact, not just as a trace of what happened.
- Make the cost measurable, so that tuning is driven by numbers rather than by impressions.
- Handle the input strictly: overflow, duplicates, malformed arguments, all rejected before anything is printed.
- Manage every allocation by hand in C, with no leak, under the 42 Norm.

## 📋 Constraints

Two stacks, `a` holding the input and `b` empty at the start, and this instruction set:

| Move | Effect |
| --- | --- |
| `sa` `sb` `ss` | Swap the top two elements of `a`, of `b`, of both at once |
| `pa` `pb` | Push the top of one stack onto the other |
| `ra` `rb` `rr` | Rotate up: the top element becomes the last one |
| `rra` `rrb` `rrr` | Rotate down: the last element becomes the top one |

- The program prints instructions and nothing else. Everything must be sorted in `a`, with `b` empty, once they are replayed.
- Numbers are `int`, given either as separate arguments or as one quoted string. Anything else (a non-numeric argument, a value outside `int`, a duplicate) prints `Error` on the error output and stops.
- No error, no output and no crash on an empty argument list, and no leak on any path.
- The bonus adds `checker`, which reads a move sequence on standard input, applies it to the stacks and answers `OK` or `KO`.
- The 42 Norm: 25 lines per function, 5 functions per file, 4 parameters, no `for`, no `switch`, no ternary.

## 🧠 How it works

### Ranks instead of values

Parsing validates the arguments, then sorts a copy of them with a merge sort and writes each element's rank back next to its value. From that point the sorting core never looks at the values again, only at ranks running from 1 to n.

This is what makes the pivots free. In a general quicksort the pivot has to be picked, and a bad pick costs balance; here the median rank of any range is known by arithmetic before the range is even examined, so every partition splits exactly in half and the recursion depth is fixed by the input size alone.

### Splitting between the two stacks

Sorting proceeds by halves, alternating stacks.

`ft_pivot_a` walks the top of `a` and, for each element, either pushes it to `b` if its rank is below the pivot or rotates it away if it is above. The half that stays in `a` is then recursively sorted the same way, until a chunk of three or fewer is left and gets ordered by a hard-coded sequence. What was pushed to `b` waits its turn: `ft_pivot_b` sends the larger part of it back to `a` while keeping the smaller part in place, and the process repeats, so the elements come back in order and pile up sorted under the ones already placed.

Rotating past elements leaves the stack turned. Rolling it back is done in whichever direction is shorter, comparing how far the stack was rotated to half its length, so a stack that was almost fully turned is finished with a few reverse rotations instead of being carried the long way round.

### Operations as data

The part that saves the most moves is not in the sorting at all.

Nothing is printed while sorting. Each move is applied to the stacks immediately, so the algorithm always sees the true state, but the move itself is appended to a queue, one for `a` and one for `b`. Those two queues are independent: a rotation of `a` and a rotation of `b` do not interfere, so their relative order can still be chosen later. A push touches both stacks, so it acts as a barrier and forces the queues to be resolved before it.

Resolving them is two passes:

- **Cancellation.** Adjacent pairs that undo each other are deleted from the queue: `ra` then `rra`, `pa` then `pb`, `sa` twice. These appear naturally at the seams between two partitions, where one step finishes by turning a stack back and the next starts by turning it again.
- **Merging.** The two queues are then interleaved into the final sequence. When the next move on `a` and the next on `b` are counterparts, they are emitted as the single combined instruction (`ra` + `rb` becomes `rr`, `rra` + `rrb` becomes `rrr`, `sa` + `sb` becomes `ss`), two lines turned into one. When they are not, the choice of which queue to advance is made by looking ahead: each candidate's counterpart is located in the opposite queue, and the one whose match is furthest away is flushed, leaving the closer pair a chance to meet.

Every collapsed pair is one line that never gets printed. On a hundred random numbers the final sequence contains fifteen to twenty combined instructions, on top of whatever the cancellation pass removed before them.

## 📊 Results

`moyenne.sh` runs the program on random permutations and reports the average, the extremes, and how many runs exceeded a given limit. Over 200 runs on 100 numbers and 50 runs on 500:

| Input | Average | Worst seen | Limit |
| --- | --- | --- | --- |
| 100 random numbers | 664 | 702 | 700 |
| 500 random numbers | 5,070 | 5,142 | 5,500 |

The 500 case clears its limit with room to spare. The 100 case sits just under it, and around one run in two hundred still goes over. The git history is the record of that being ground down: the first working version averaged 800 instructions on a hundred numbers, a later one 689 with a quarter of the runs still above the limit, and the tuning continued from there.

## 🛠️ Tech Stack

<p>
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Shell-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white" alt="Shell"/>
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux"/>
  <img src="https://img.shields.io/badge/GNU%20Make-A42E2B?style=for-the-badge&logo=gnu&logoColor=white" alt="GNU Make"/>
</p>

C compiled with `cc -Wall -Wextra -Werror`, no external library. The stacks and the operation queues are the same structure throughout, a doubly linked circular list, which makes a rotation a move of the head pointer rather than a shift of anything. `includes/libftprintf/` bundles the [libft](https://github.com/acardona123/42_libft) and `ft_printf` written earlier in the cursus, and `includes/gnl/` the `get_next_line` the bonus checker reads its input with. The benchmark and input generators are shell.

## 🚀 Getting Started

```bash
git clone https://github.com/acardona123/42_Push_swap.git
cd 42_Push_swap
make          # push_swap
make bonus    # checker
```

## 📖 Usage

```bash
./push_swap 4 12 -3 7 0
./push_swap "4 12 -3 7 0"
```

```
pb
ra
sa
...
```

`randomizer.sh` generates a shuffled range to feed it:

```bash
./randomizer.sh 0 99          # a random permutation of 0..99, space separated
./push_swap $(./randomizer.sh 0 99) | wc -l
```

And the checker reads a sequence back:

```bash
ARG="$(./randomizer.sh 0 99)" && ./push_swap $ARG | ./checker $ARG
OK
```

## 🧪 Tests

Correctness and cost are checked separately, because a sequence can be valid and still bad.

- **Correctness.** The output is piped into `checker`, which must answer `OK` on a valid sort and `KO` on a deliberately corrupted sequence.
- **Cost.** `moyenne.sh MIN MAX ITER LIM` sorts `ITER` random permutations of the range and reports the average, minimum and maximum number of instructions, plus how many runs went above `LIM`. Runs above the limit are printed in red as they happen, so a rare bad case is visible rather than buried in the average.
- **Parsing.** Checked by hand on the cases that are easy to get wrong: `2147483648`, `+0`, `-0`, `007`, a repeated value, an empty argument, a lone number, no argument at all.
- **Units.** Each file in `test/` is a standalone `main()` written while building the corresponding layer, exercising it in isolation: list construction, the merge sort behind the ranking, the individual stack operations, the cancellation pass. They are compiled in through the `C_TEST` variable in the Makefile rather than shipped in the final binary.
- Also validated against [42_tester_pushswap](https://github.com/acardona123/42_tester_pushswap), and checked under Valgrind for leaks on both the normal and the error paths.

## 📁 Structure

```
srcs/
  main.c                        argument handling and the top-level run
  parsing.c parsing_bis.c       validation, and the value to rank conversion
  indexation_fusion_sort.c      merge sort used to compute the ranks
  sorting_main.c                the recursion, and the hard-coded cases of three or fewer
  sorting_pivots.c              partitioning a range between the two stacks
  piles_op_optimisation*.c      the operation queues: recording, cancelling, merging, printing
  circlst/                      the circular list: build, rotate, swap, push, free
bonus/                          checker, sharing the same list and parsing code
includes/
  push_swap.h                   structures and prototypes
  libftprintf/  gnl/            libft, ft_printf and get_next_line from earlier projects
test/                           per-layer test mains, wired in through the Makefile
randomizer.sh  moyenne.sh       random input, and the benchmark
```

## 📚 Resources

- [Quicksort](https://en.wikipedia.org/wiki/Quicksort) for the partitioning idea, adapted here to a pivot that is known in advance.
- [Merge sort](https://en.wikipedia.org/wiki/Merge_sort) for the ranking pass.

---

<p align="center"><sub>🏫 Project from the <strong>42</strong> common core, School 42 Paris.</sub></p>
