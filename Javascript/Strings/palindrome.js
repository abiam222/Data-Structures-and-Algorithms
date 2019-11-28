main();

function main() {
    let str = "supercalifadrowlakdnchfacedjie";
    let str2 = "eijdecafhcndkalwordafilacrepus";

    //base case
    if (str.length !== str2.length) return console.log( "is not Palindrome" );

   console.log(  ( isPal(str, str2) ? "is Palindrome" : "is not Palindrome") );
}

function isPal(str, str2) {
    let low=0, high=str.length-1;

    while (low < high) {
        if (str[low++] !== str2[high--]) return false;
    }
    return true;
}