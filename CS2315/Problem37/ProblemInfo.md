
## Problem 33 (Inversions using a random array of integers)

This problem consists of counting the inversions needed to organize a random array of integers from low to high.

The tasks needed to be done were to complete `MaximumInversions`, `NumberOfInversions` and `DoComparisonCountingSort`.

1. `MaximumInversions` was achieved by merely multiplying the inputted value by itself minus one then dividing by two as given in
the problem document.

2. `NumberOfInversions` was achieved by comparing the array values inside `A[]` (`i ` being zero, `j` being `i` plus one) to see if the value in `i` is greater than `j` to count it as a inversion.

3. `DoComparisonCountingSort` was achieved using the required `*count` pointer array and `S[n]`. To do so, count was made to be fully zero, then count is added by the greatest number if the the value in `i` is greater than `j` or less than `j` along with numberCompares. Afterwards `S[n]` was given the values of within `A[]` that were fixed from low to high then applied back to the `A[]` array for printing.
