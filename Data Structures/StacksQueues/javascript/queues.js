module.exports = class Queue {

    //js currently no method overload hence only one constructor
    constructor(items) {
        this.items = [];
        if (items) this.items = items;
    }

    //enqueue
    push(elem) {
       this.items.push(elem);
       //also try it not the javascript way
    }

    //deque
    pop() {
        this.items.shift();
    }

    //0 4 3 2 1
    front() {
        //console.log( this.items[0] )
        return this.items[0]
    }

    isEmpty() {
        return (this.items.length === 0) ? true : false;
    }

    print() {
        this.items.forEach( (val, index) => {
            console.log(val + "\n");
        });
    }
}

/*
implement the queue functions

enqueue
deque 
front
isEmpty
printQueue

*/

// main()

// function main() {
//     let q = new Queue();
//     let q2 = new Queue();

//     q.push(5);//5
//     q.push(7);//5 7
//     q.push(8);//5 7 8
//     q2.push(10);//10
//     q.front();//5
//     q.pop();//5
//     q.front();//7
//     q.print();//7 8
//     q.pop();//7
//     q.print();//8
// }