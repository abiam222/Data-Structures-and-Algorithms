/*

We want to see if the string is an anagram

Anagram - a word, phrase or name formed by rearranging the letters of another 
e.g. cinema, formed form iceman 

*/

var heapSort = require('../global/heapsort.js');

console.log(heapSort)

main();

function main() {
    const NS_PER_SEC = 1e9;
    let str = "cinema";
    let str2 = "iceman";

    //let itr=1000;
    //while (itr > 0) {
    //const time = process.hrtime();
    
   console.log( ( isAnagram(str, str2) ) ? "is anagram" : "not anagram" );
    
    //const diff = process.hrtime(time);
    //console.log(`${diff[0] * NS_PER_SEC + diff[1]}`);//in nano
   
    //itr--;
    //}
}

function isAnagram(str, str2) {
    //base case
    //if size is different return 0
    if (str.length !== str2.length) return false;

    //sort
    str = sortString(str);
    str2 = sortString(str2);

    for (let i in str) {
        if (str[i] !== str2[i]) return false;
    }
    return true;
}

function sortString(str) {
    return str.split('').sort().join('');
};

