/*

We want to see if the string is an anagram

Anagram - a word, phrase or name formed by rearranging the letters of another 
e.g. cinema, formed form iceman 

There are two solutions 

isAnagram has the default javascript sort
isAnagram heap uses the heap algorithm

*/

var heapSort = require('../global/heapsort.js');

main();

function main() {
    const NS_PER_SEC = 1e9;
    let str = "cinema";
    let str2 = "iceman";

    let itr=1000;
    while (itr > 0) {
    const time = process.hrtime();
    
   //( isAnagram(str, str2) ) ? "is anagram" : "not anagram";
   ( isAnagramHeap(str, str2) ) ? "is anagram" : "not anagram";
    
    const diff = process.hrtime(time);
    console.log(`${diff[0] * NS_PER_SEC + diff[1]}`);//in nano
   
    itr--;
    }
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

function isAnagramHeap(str, str2) {
    //base case
    //if size is different return 0
    if (str.length !== str2.length) return false;

    //sort
    str = heapSortMain(str);//heapSort(str)
    str2 = heapSortMain(str2);

    for (let i in str) {
        if (str[i] !== str2[i]) return false;
    }
    return true;
}



// function heapSortMain(str) {
//     //let str = "abiam";
//     let arr = str.split('');
//     let updateArr = [];
    
//     arr.forEach( (val, index) => {
//         updateArr.push(val.charCodeAt(0));
//     });
    
//     updateArr = heapSort(updateArr);
    
//     let updateArr2 = [];
//     updateArr.forEach( (val, index) => {
//         updateArr2.push( String.fromCharCode(val) );
//     });
    
//     let finalStr = updateArr2.join('');
//     //console.log(finalStr)
//     return finalStr;
// }

// function heapSort(array) {
//     // Build our max heap.
//     buildMaxHeap(array);
  
//     // Find last element.
//     lastElement = array.length - 1;
  
//     // Continue heap sorting until we have
//     // just one element left in the array.
//     while(lastElement > 0) {
//       swap(array, 0, lastElement);
  
//       heapify(array, 0, lastElement);
  
//       lastElement -= 1
//     }
//     return array;
//   }

//   function buildMaxHeap(array) {
//     var i;
//     i = array.length / 2 - 1;
//     i = Math.floor(i);
  
//     // Build a max heap out of
//     // all array elements passed in.
//     while (i >= 0) {
//       heapify(array, i, array.length);
//       i -= 1;
//     }
//   }

// function heapify(heap, i, max) {
//     var index, leftChild, righChild;
    
//     while(i < max) {
//       index = i;
  
//       leftChild = 2*i + 1;
//       righChild = leftChild + 1;
  
//       if (leftChild < max && heap[leftChild] > heap[index]) {
//         index = leftChild;
//       }
  
//       if (righChild < max && heap[righChild] > heap[index]) {
//         index = righChild;
//       }
        
//       if (index == i) {
//         return;
//       }
  
//       swap(heap,i, index);
      
//       i = index;
//     }
//   }

//   function swap(array, firstItemIndex, lastItemInde) {
//     var tmp = array[firstItemIndex];
    
//     // Swap first and last items in the array.
//     array[firstItemIndex] = array[lastItemInde];
//     array[lastItemInde] = tmp;
//   }
