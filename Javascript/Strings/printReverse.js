/*

print string in reverse

*/

main();

function main() {
    let str = "alsdflkjdfkadasdfl";
    str = str.split("").reverse().join("");
    //split each by letter
    //["a","l","s"...]
    //reverse each letter
    //join all items in array
    console.log(str);

    //long way to do it
    let str2 = "alsdflkjdfkadasdfl";
    str2 = str2.split("");//this make an array that I can now use with reverse and join
    str2 = str2.reverse();
    //The join() method creates and returns a new string by concatenating all of the elements in an array
    str2 = str2.join("");
    console.log(str2);
}