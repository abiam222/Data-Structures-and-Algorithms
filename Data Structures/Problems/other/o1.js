
/*
Find 2 pairs that equal the target number
assume all cases are valid
assume there are only and only two values that equal 
to the target number

it will output either "No valid pairs" or "<x> and <y>"
where x and y are the two values that when added are
equal to the target value

[14,13,6,7,8,10,1,2] 3 == "1 and 2"
[2,2] 4 == "2 and 2"
[2] 4 == "No valid pairs"

[4,5,1,2] 7

also say space complexity
*/

main();

function main() {
    //init vars
    console.time("start");
    let arr = [14,13,6,7,8,10,1,2];//space n
    let target = 3;
    let vals = new Map();
    let found = false;
    let x, y;

    //base case
    //array is empty?
    if (arr.length == 0) console.log("No valid pairs");

    //algo
    //loop through array
    //if num > target (ignore) 
    //if num <= target (can be equal but other is zero)
    //then 

    //O(n) loop through array and put in map
    //do another loop of map O(n) now do this
    //map[i]-target = number. if this number is in the
    //map then you found both numbers, if not continue
    arr.forEach( (val, index) => {
        vals.set( val, 1);
    });
    //console.log(vals)

    //O(n)
    vals.forEach((val, key) => {
           number = Math.abs( key-target );
           if (vals.get(number)) {
                found = true;
                x = key;
                y = number;
                return;//if this doesn't work say if (... && !found)
           }
    });

    console.log( (found) ? `${y} and ${x}` : "No valid pairs")
    console.timeEnd("start");
}