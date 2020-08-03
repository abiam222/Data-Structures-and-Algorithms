
main();

function main() {
    let nums = [3,5,12,15,20,34,66,78,98,300,400,500,800,1000,4432,23423];//in order
    console.time("first")
    console.log( binarySearch(nums, 234) ? "FOUND" : "NOT FOUND" );
    console.timeEnd("first");
}

//for this to work the data must be in order
function binarySearch(nums, elem) {
    let low=0, high=nums.length-1, mid=0;
   
    while (low <= high) {
        mid = Math.floor( ( low + high ) / 2 );
        if (nums[mid] === elem) return true;
        if (nums[mid] > elem) high=mid-1;
        if (nums[mid] < elem) low=mid+1;
    }
    return false;
}