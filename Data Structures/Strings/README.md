# Performance Testing 

Each file contains multiple functions, and within each function lies an algorithm that solves the stated problem.
I will be testing and comparing each function to test
the length of time for completion. The final result
can be found in the file itself or its excel file.

E.g.
In the printReverse.js file there are three different functions

* usingFunctions
* looping
* usingLodash

Each of these function has a variation of:
 How to reverse a string:
    UsingFunctions - I used Javascript methods
        ```javascript
        split
        reverse
        join
        ```
    Looping - I looped through the string array backwards
    usingLodash - Used the reverse lodash function

I then run each iteration about 1K or more times. I publish
this data in the excel file then check the average time.


# Excel

Each row is for each function.
Next to it is the average time for each iteration.
in each <name>.xlsx file.

Each function was run over 1000K times.