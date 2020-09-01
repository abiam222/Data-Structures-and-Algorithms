//this algo does

/*
All powerset combinations

[ 1, 2, 3 ]
[ 1, 2 ]
[ 1, 3 ]
[ 1 ]
[ 2, 3 ]
[ 2 ]
[ 3 ]
[]
*/

var subsets = function(nums) {
    let result = [];
    dfs([], 0);
    
    function dfs(current, index){
        result.push(current);
        for(let i = index; i < nums.length; i++) {
            //i=0, i=1
            //dfs( current.concat(nums[0])= [].concat(1)=[1], 0+1=1 )
            //dfs( current.concat(nums[1])= [1].concat(2)=[1,2], 1+1=2 )
             //dfs( current.concat(nums[2])= [1,2].concat(3)=[1,2,3], 2+1=3 )
             //dfs( current.concat(nums[2])= [1].concat(3)=[1,3], 2+1=3)
             //...
            dfs(current.concat(nums[i]), i + 1);
        }
    }
    return result;
};

//[[]]
//[ [], [1] ]
//[ [], [1], [2] ]
//[ [], [1], [2], [3] ]

// [], [1]
//[], [2], 
// [], [3] 

console.log( subsets([1,2,3]) )

// var subsets = function(nums) {
//     let res = [[]];
//     let cur = [[]];
    
//     nums.map(x => {
//         cur = res.map(r => [...r, x]);
//         res = [...res, ...cur]
//     })
    
//     return res;
// };