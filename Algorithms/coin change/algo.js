var coinChange = function(coins, amount) {
    let Max = amount + 1;
    let dp=[];
      for(let i=0;i<amount+1;i++){
          dp.push(Max);//build array of amount+1 , amount+1 times
      }
      //console.log(dp)
      dp[0] = 0;//first array has 0 amount
      for (let i = 1; i <= amount; i++) { //amount times 
          for (let j = 0; j < coins.length; j++) { //do this every cons.length times
              if (coins[j] <= i) {
                  dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
              }
          }
      }
       console.log(dp)
      return dp[amount] > amount ? -1 : dp[amount];
};

coinChange([1,2,5],11)

/*
Build an array of amount of coins

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

will have our array of amount of coins it takes to get to 11,
using Dynamic Programmin
[ 0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3 ]


Example 2:

Input: coins = [2], amount = 3
Output: -1

*/