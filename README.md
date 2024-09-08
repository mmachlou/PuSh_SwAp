# Push_Swap - Project

Welcome to the **Push_Swap** project, part of the 42 School curriculum. This project is a highly challenging algorithmic problem designed to optimize sorting using a minimal number of stack operations. The goal is to sort a list of integers using two stacks and a set of predefined operations.

---

## Table of Contents

1. [Introduction](#introduction)
2. [How It Works](#how-it-works)
3. [Getting Started](#getting-started)
4. [Usage](#usage)
5. [Algorithm Performance](#algorithm-performance)
6. [Examples](#examples)
7. [Project Structure](#project-structure)
8. [Evaluation](#evaluation)

---

## Introduction

The **Push_Swap** project is an algorithmic challenge aimed at sorting a list of integers with the fewest possible moves. The task involves using only two stacks and a limited set of operations to achieve this. The complexity lies in balancing efficiency and minimizing the number of operations required.

The key objectives of this project include:

- Developing an efficient sorting algorithm.
- Minimizing the number of stack operations.
- Maintaining compliance with 42 School's strict coding and performance standards.

---

## How It Works

### Stack Operations

You are given two stacks, `A` and `B`, and you can perform the following operations:

- `sa` (swap A): Swap the first two elements at the top of stack A.
- `sb` (swap B): Swap the first two elements at the top of stack B.
- `ss`: Swap both stacks A and B.
- `pa` (push A): Take the first element from the top of B and move it to the top of A.
- `pb` (push B): Take the first element from the top of A and move it to the top of B.
- `ra` (rotate A): Shift all elements of stack A upwards.
- `rb` (rotate B): Shift all elements of stack B upwards.
- `rr`: Rotate both stacks A and B.
- `rra` (reverse rotate A): Shift all elements of stack A downwards.
- `rrb` (reverse rotate B): Shift all elements of stack B downwards.
- `rrr`: Reverse rotate both stacks A and B.

The challenge lies in sorting the input with the smallest number of these operations.

---

## Getting Started

### Prerequisites

To get started, ensure you have the following tools installed:

- **GCC**: The GNU Compiler Collection for compiling C programs.
- **Make**: A build automation tool for managing compilation.

### Installation

Clone this repository to your local machine:

```bash
git clone https://github.com/mmachlou/PuSh_SwAp.git
cd PuSh_SwAp
```

Compile the program by running:

```bash
make
```

This will generate the `push_swap` executable in the project root.

---

## Usage

Once compiled, you can use the program to sort a list of integers by passing the integers as arguments to the executable:

```bash
./push_swap [list of integers]
```

You can measure the performance of the sorting algorithm using the `wc -l` command to count the number of operations required:

```bash
./push_swap [list of integers] | wc -l
```

---

## Algorithm Performance

The **Push_Swap** algorithm is evaluated based on its ability to sort input with the fewest moves. Below are benchmarks for two sample inputs:

### Benchmark for 100 Numbers

```bash
$ ./push_swap 83 8 66 29 91 31 13 22 9 69 42 63 23 28 41 56 39 84 52 19 94 48 43 37 12 64 36 65 87 92 33 7 81 77 38 46 20 97 86 55 93 50 16 88 14 100 59 6 1 72 17 26 67 11 49 25 60 15 79 73 76 35 89 18 71 4 10 32 74 70 96 44 40 98 30 99 2 82 47 53 75 57 27 54 21 3 45 51 85 80 68 24 61 78 5 58 95 90 62 34 | wc -l
```

**Output**: `562 operations`

### Benchmark for 500 Numbers

```bash
$ ./push_swap 190 291 438 91 385 154 221 85 194 380 248 367 58 402 1 65 267 18 264 174 312 102 294 256 293 113 38 121 288 266 126 322 369 423 191 235 24 290 377 457 459 466 347 189 206 200 446 222 4 395 177 475 68 401 225 417 133 219 358 6 49 8 31 99 340 70 116 447 227 315 428 353 51 349 5 20 176 474 272 16 122 123 287 186 448 134 203 327 335 449 30 386 89 366 29 500 63 98 182 168 103 332 96 136 115 345 326 204 61 213 75 7 210 14 330 90 491 139 302 420 440 108 193 188 436 301 127 265 199 78 54 376 81 388 132 22 372 169 166 119 137 378 344 155 165 379 359 178 432 469 304 21 307 411 400 408 458 157 216 433 382 84 79 412 152 243 211 351 249 328 26 338 25 483 277 306 496 329 268 298 175 292 183 300 142 456 488 276 463 364 460 105 422 100 251 118 73 245 101 259 492 275 283 464 146 484 241 309 207 232 269 421 399 28 202 404 413 305 52 45 416 271 331 467 36 255 443 173 42 111 252 394 406 479 149 472 397 273 352 487 405 258 77 473 281 162 192 220 161 296 131 97 355 129 311 43 240 82 396 231 320 497 253 362 164 429 135 64 389 34 144 415 72 470 383 499 93 237 67 15 56 493 242 295 170 41 368 403 95 337 39 461 212 324 107 430 236 40 53 46 348 489 86 158 333 228 239 325 476 261 419 180 424 74 371 226 229 409 342 373 48 365 197 151 205 167 187 80 425 482 357 32 37 398 114 454 246 57 486 426 66 147 160 150 318 450 471 104 393 140 230 87 184 2 125 109 217 442 477 310 341 414 47 124 179 112 308 55 110 478 181 387 156 33 224 435 445 196 465 198 233 244 390 316 153 69 120 145 163 314 303 346 384 247 234 495 490 148 257 254 468 171 83 321 27 284 215 11 130 462 285 374 323 88 427 439 195 138 494 319 297 128 286 334 260 431 299 485 375 62 391 392 44 159 363 250 59 437 480 35 76 92 354 60 498 444 141 106 274 481 339 19 270 50 407 361 13 262 12 209 441 143 410 289 185 317 218 278 282 172 343 453 313 117 280 263 223 336 3 208 71 452 370 9 214 434 381 94 279 17 356 350 455 418 10 360 238 23 201 451 | wc -l
```

**Output**: `4587 operations`

---

## Examples

For example, sorting a list of 5 random integers:

```bash
./push_swap 5

 3 1 2 4
```

The output will be the necessary commands to sort the list.

---

## Project Structure

- **src/**: Contains the source code implementing the algorithm and operations.
- **includes/**: Header files defining the function prototypes and structures.
- **Makefile**: Contains the compilation rules and dependencies.

---

## Evaluation

The **Push_Swap** project is evaluated based on:

- **Correctness**: The ability to sort the stack correctly.
- **Efficiency**: The number of operations required to achieve sorting.
- **Code Quality**: Adherence to 42 School's coding standards.
- **Performance**: The algorithm's performance when tested against various input sizes.
