## Subject Summary

This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

2개의 `stack` 이 주어지고 입력으로 `data`가  들어올 때
정해진 operation을 작동하여
적절한 알고리즘을 사용하여 data를 오름차순으로 정렬하는 과제이다.

## 필요개념
Stack, Queue, Deque 

<aside>
💡 본 과제는 2개의 stack을 사용한다고 하지만

정확하게 stack이라 보기는 어렵다.

stack 보다는 deque에 가까운 자료구조의 형태를 띄고 있다.

(operation을 보면 이해가 가능하다 추후에 이야기하자)

</aside>

## stack을 구현하기 위해 사용한 자료구조

필자는 본 subject 에 사용될 stack 및 operation을 구현하기 위해

linked list(단 방향)으로 구현하였다.

양 방향 linked list, array 다양한 방법들이 있지만 앞선 과제들도 동일하게 사용하였기에

가장 익숙한 방법을 사용하였다.

## Operations

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.

<aside>
💡 rotate 와 reverse rotate 명령어로 인해 `stack`이 `deque` 처럼
위 아래로 `data` 접근이 가능해진다.
</aside>

## Code Flow Chart

![스크린샷 2024-04-03 오전 10 10 05](https://github.com/AriSongYe/push_swap/assets/82326075/2c8dc095-9d6a-40d6-b2ce-841bb4d48672)


## Parsing

Code Flow Chart에서 확인한 것 처럼 

input으로 들어오는 `data` 들을 확인하고 Parsing 합니다.

1. 중복된 숫자가 있는가
2. 숫자인가? (‘+’, ‘-’ 를 제외)
3. int 범위를 넘어가는 가?
4. 2개 이상의 숫자가 들어 왔는가?
5. 정렬되어 있는가?

다음과 같은 조건을 check_valid 를 통과한 `data` 들을 `int` 배열에 담아줘야 합니다.

<aside>
💡 이 때 숫자의 개수 만큼 arg로 들어온다는 보장이 없습니다.

</aside>

예를 들어

“1 2 3” “4 5 6” 7 “ 8 9 “ “ -10 -20 +10 +20 0”

과 같이 `arg` 의 개수는 5개 이지만 들어온 숫자는 14개 입니다.

“1 2 3 4 5 6” 7

과 같이 `arg` 의 개수는 2개 이지만 들어온 숫자는 7개 입니다.

1 2 3 4 5 6 7

과 같이 `arg` 의 개수는 7개 이지만 들어온 숫자는 7개 입니다.

“1 2 3 4 5 6 7”

과 같이 `arg` 의 개수는 1개 이지만 들어온 숫자는 7개 입니다.

이런 다양한 경우를 처리해주기 위하여

모든 `argv`를 돌며 들어온 숫자만큼 동적할당을 해주고

parsing 과정이 필요합니다.

## 적은 숫자 최적화

모든 경우를 동일한 알고리즘을 적용할 경우

적은 숫자가 들어왔을 경우 필요 이상에 명령어를 사용하게 됩니다.

~~(솔직히, 평가지에 있는거 만족하려고 해야합니다 쥬륵,,)~~

적은 숫자가 들어왔을 경우를 예외 처리해줘야 합니다.

## 모래시계 알고리즘

[push_swap 을 위한 알고리즘](https://www.notion.so/push_swap-b0df9069613840519465222af89794a1?pvs=21) 

## Checker (BONUS PART)

subject에서 제공해주는 checker를 동일하게 구현해보자.

동일한 `arg`  입력을 받고 출력된 명령어들을 읽어서

올바르게 정렬이 되었는지 확인해주는 프로그램을 작성하는 것이 bonus 과제이다.

mandatory를 완벽히 작성했다면 정말 쉽게 작성할 수 있다.

대부분의 코드를 mandatory에서 끌어다가 복사하여 만들었다.

`get_next_line`을 통해 읽어들이고 그대로 수행하여 정렬되어 있으면 OK

아니면 KO

에러가 발생했다면 `Error`를 출력해주면 된다.

### 워스트 케이스

499 497 495 493 491 489 487 485 483 481 479 477 475 473 471 470 472 474 476 478 480 482 484 486 488 490 492 494 496 498 469 467 465 463 461 459 457 455 453 451 449 447 445 443 441 440 442 444 446 448 450 452 454 456 458 460 462 464 466 468 439 437 435 433 431 429 427 425 423 421 419 417 415 413 411 410 412 414 416 418 420 422 424 426 428 430 432 434 436 438 409 407 405 403 401 399 397 395 393 391 389 387 385 383 381 380 382 384 386 388 390 392 394 396 398 400 402 404 406 408 379 377 375 373 371 369 367 365 363 361 359 357 355 353 351 350 352 354 356 358 360 362 364 366 368 370 372 374 376 378 349 347 345 343 341 339 337 335 333 331 329 327 325 323 321 320 322 324 326 328 330 332 334 336 338 340 342 344 346 348 319 317 315 313 311 309 307 305 303 301 299 297 295 293 291 290 292 294 296 298 300 302 304 306 308 310 312 314 316 318 289 287 285 283 281 279 277 275 273 271 269 267 265 263 261 260 262 264 266 268 270 272 274 276 278 280 282 284 286 288 259 257 255 253 251 249 247 245 243 241 239 237 235 233 231 230 232 234 236 238 240 242 244 246 248 250 252 254 256 258 229 227 225 223 221 219 217 215 213 211 209 207 205 203 201 200 202 204 206 208 210 212 214 216 218 220 222 224 226 228 199 197 195 193 191 189 187 185 183 181 179 177 175 173 171 170 172 174 176 178 180 182 184 186 188 190 192 194 196 198 169 167 165 163 161 159 157 155 153 151 149 147 145 143 141 140 142 144 146 148 150 152 154 156 158 160 162 164 166 168 139 137 135 133 131 129 127 125 123 121 119 117 115 113 111 110 112 114 116 118 120 122 124 126 128 130 132 134 136 138 109 107 105 103 101 99 97 95 93 91 89 87 85 83 81 80 82 84 86 88 90 92 94 96 98 100 102 104 106 108 79 77 75 73 71 69 67 65 63 61 59 57 55 53 51 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 49 47 45 43 41 39 37 35 33 31 29 27 25 23 21 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 19 17 15 13 11 9 7 5 3 1 0 2 4 6 8 10 12 14 16 18
