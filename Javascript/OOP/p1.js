/*

netflix and amazon

//name, subject, id, score  
{
    {abiam, math, 24344, 55}
    {nick, science, 23555, 20}
    {nick, science, 12312, 32}
    {abiam, math, 24344, 75}
    {nick, math, 12312, 77}
}

Find averages of each test for each student 

Usually if its in an object like this you can use OOP (classes)
Also when you code use best practices. These people really
care about how you write your code, how you write your variables. 
Constantly debugging

Write it like a real program, the OOP way. 
It has to be perfect

*/

//Ima try to solve it with and without OOP (2 oop in js ways es6 and non)

class Obj {
    constructor(name, subject, id, score) {
        this.name = name;
        this.subject = subject;
        this.id = id;
        this.score = score;
    }
}


/*
[
    {abiam, math, 24344, 55}
    {nick, science, 23555, 20}
    {nick, science, 12312, 32}
    {abiam, math, 24344, 75}
    {nick, math, 12312, 77}
]

*/

//start with main
main();

function main() {
    const data = [];
    const file = [
        [ "abiam", "math", "24344", "55" ],
        ["nick", "science", "23555", "20"],
        ["nick", "science", "12312", "32"],
        ["abiam", "math", "24344", "75"],
        ["nick", "math", "12312", "77"],
    ]

    //space time of n for file
    //3 maps where they are distincts(n)
    //so 3*distincts(n) + n = n

    //memory just n because n + n = n
    
    //insert file data in an object
    for (let i=0;i<file.length;i++) {
             //read from file each line
            data.push(new Obj(file[i][0],file[i][1],file[i][2],parseInt(file[i][3])));
    }

    //abiam = 55+75
    //nick = 20
    //nick = 32
    //but id needs to be the same 
   // console.log(data)
    //put errr in a map
    let vals = new Map();
    let amt = new Map();//the amt we will divide by in the end

    //O(n) time
    data.forEach((val, index) => {
        //key value pair
        //is in map
        if (vals.get(val.id)) {
          amt.set(val.id, amt.get(val.id) + 1);
          let newScore = vals.get(val.id) + val.score;
          vals.set(val.id, newScore);
        } else {
            //else just add value
            vals.set(val.id, val.score);
            amt.set(val.id, 1);
        }
    });

    //console.log(vals)
    //console.log(amt)

    let finals = new Map() //return key average pair
    //O(n) average
    //each value in map
    vals.forEach( (val, key) => {
        // console.log(val)
        // console.log(key)
        let average = val / amt.get(key);
        finals.set(key, average);
    });

    console.log(finals);
}