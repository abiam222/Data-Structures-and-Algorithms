/*

print string in reverse

Based on the calculations (printReversedata.xcel file) 
the method lodash destroys the other functions
looping took 65215.078 nano
usingFunc took 26258.72 nano seconds
usingLodash took 13400.612 nano seconds
on average (per 1000 runs)

*/

var _ = require('lodash');

main();

function main() {
    const NS_PER_SEC = 1e9;
    let str = "alsdflkjdfkadasdfasdfsadfjjkweoiruworusdfclkajasldfsfkbkjadhfhsiouiuewecnlafjlasdfl";
    let itr=1000;
    while (itr > 0) {
    const time = process.hrtime();
    //console.time("start");
    //usingFunctions(str)
    usingLodash(str);
    //looping(str);
    reallyLongToTest()
    const diff = process.hrtime(time);
    console.log(`${diff[0] * NS_PER_SEC + diff[1]}`);//in nano
    //console.timeEnd("start");
    itr--;
    }
}

//just using function O(n)
//retry this , I moved the using functions comments
function usingFunctions(str) {
    str = str.split("").reverse().join("");
    return str;
    //split each by letter
    //["a","l","s"...]
    //reverse each letter
    //join all items in array
    //console.log(str);
    //long way to do it
    // let str2 = "alsdflkjdfkadasdfl";
    // str2 = str2.split("");//this make an array that I can now use with reverse and join
    // str2 = str2.reverse();
    // //The join() method creates and returns a new string by concatenating all of the elements in an array
    // str2 = str2.join("");
    // console.log(str2);
}

//looping O(n)
function looping(str) {
    let newStr="";
    for (let i in str) {
        newStr += str[str.length-i-1];
    }
    return newStr;
}


function reallyLongToTest() {
    let p=100000;
    while(p>0) {
        p--;
    }
}

function usingLodash(str) {
    str = str.split("");
    _.reverse(str);
    str = str.join("");
   return str
}