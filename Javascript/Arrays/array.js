runArr();

function runArr() {
    let arr = [5,6,7,8];
    let arr2 = [1,2,3,4];
    let arr3 = [[]];

    //map, reduce, and the other one 

    console.log(arr2.length)
    arr2 = arr2.concat(arr);
    console.log(arr2)

    arr2.reverse();
    console.log(arr2);

    console.log(5/2) //2.5
    console.log(Math.round(5/2)) //3
    console.log(Math.floor(5/2)) //2

    //from a to z
    for(let i = 'a'.charCodeAt(0); i <= 'z'.charCodeAt(0); i++) {
        console.log( i ) //number
        console.log( String.fromCharCode(i) ) //letter
        //a = 97 to z = 122
    }
}