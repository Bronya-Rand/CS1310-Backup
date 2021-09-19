
## Problem 33 (Towers of Hanoi)

This problem consists of making a recursive solution to the Towers of Hanoi math problem based off Introduction To The Design And Analysis Of Algorithms (3rd Edition) textbook and problem sheet.

The tasks needed to be done were to make `DoTowersOfHanoi` recursive depending on certain requirements.

1. If you are moving from Disk F to Disk H, make T the auxilary (I guess a fancy name for temp location) and subtract 1 from `n` whilst still using `pegs`.
    ```c
    DoTowersOfHanoi((n - 1), F, H, T, pegs);
    ```
2. If you are moving from Disk H to Disk T, make F the auxilary and subtract 1 from `n` whilst still using `pegs`.
    ```c
    DoTowersOfHanoi((n - 1), H, T, F, pegs);
    ```
