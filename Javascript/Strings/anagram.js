/*

We want to see if the string is an anagram

Anagram - a word, phrase or name formed by rearranging the letters of another 
e.g. cinema, formed form iceman 

There are two solutions 

isAnagram has the default javascript sort
isAnagram heap uses the heap algorithm

Try small test case
Large test case
complex test case

For small case
isAnagram was faster than isAnagramHeap (check anagramData)
I believe the sorting default algo is fater for small length

*/

var heapSort = require("../global/heapsort.js");

main();

function main() {
  const NS_PER_SEC = 1e9;
  let str = "cinemaasdfqwertyuiopcinemaasdfqwertyuiopcinemaasdfqwertyuiop";
  let str2 = "ieirtqoswceapmdyaunfieirtqoswceapmdyaunfieirtqoswceapmdyaunf";
  //let str = iceman
  //let str2 = cinema

  //base case
  if (str.length !== str2.length) return false;

  let itr = 1000;
  while (itr-- > 0) {
    const time = process.hrtime();
    //( isAnagram(str, str2) ) ? "is anagram" : "not anagram" ;
    //( isAnagramHeap(str, str2) ) ? "is anagram" : "not anagram";
    isAnagramMap(str, str2) ? "is anagram" : "not anagram";

    const diff = process.hrtime(time);
    console.log(`${diff[0] * NS_PER_SEC + diff[1]}`); //in nano
  }
}

function isAnagram(str, str2) {
  //sort
  str = sortString(str);
  str2 = sortString(str2);

  for (let i in str) {
    if (str[i] !== str2[i]) return false;//this works breaks out.
  }
  return true;
}

function sortString(str) {
  return str
    .split("")
    .sort()
    .join("");
}

function isAnagramHeap(str, str2) {
  //sort
  str = heapSort(str); //heapSort(str)
  str2 = heapSort(str2);

  for (let i in str) {
    if (str[i] !== str2[i]) return false;
  }
  return true;
}

function isAnagramMap(str, str2) {
  let count = new Map();
  let found = true;

  if (str.length !== str2.length) return false;

  //faster than sort. You are just putting items in a map
  for (let i = 0; i < str.length; i++) {
    count.set(str[i], count.get(str[i]) + 1 || 0);  //count[str[i]]++;
    count.set(str2[i], count.get(str2[i]) - 1 || 0);     //count[str2[i]]--;
  }

  let BreakException = {};

  //other check the string where here will always either be faster
  //or as fast because it won't ever check duplicates (if there are any)
  try {
    count.forEach( (val, key) => {
        if (val === 0) { found = false; throw BreakException;}
    });
  } catch(e) {
    if (e !== BreakException) throw e;
  }
  
  return found;
}