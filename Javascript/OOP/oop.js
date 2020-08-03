const fetch = require('node-fetch'),//or request, node-request
Promise = require('promise');

class User {
    constructor(name, age, email) {
        this._name = name;//underscore is encapsulation. Private
        this.age = age;
        this.email = email;
    }

    increaseAge() {
        this.age += 1;
    }

    static staticMethod() {
        console.log('I am a static method');
    }

    get name() {
        return this._name;//this._name
    }

    set name(newName) {
        this._name = newName;//this._name private underscore
    }

    async getAPI() { //asyn functions return promise
        try {
            console.log('start')
            const groceriesPromise = fetch(`https://api.hunter.io/v2/email-finder?domain=vanguard.com&first_name=Dustin&last_name=Moskovitz&api_key=298345128b334ba3cbf0c4dbf5f6f1f1eecddc22`);
            const promise = [groceriesPromise];
            const [groceriesResponse] = await Promise.all(promise);
            const dataJSON = await groceriesResponse.json();
            console.log(dataJSON.data);
        } catch(e) {
            console.log(e)
            //res.sendStatus(500).json(e);
        }
    }

    forLoops() {
        //for in, for of, forEach, for
        let veg = ['candy', 'cat', 'dog'];

        for (let x in veg) {
            console.log(veg[x]);
        }

        veg.forEach( (x,y) => {
            console.log(x + ' ' + y);
        });
    }

}

class Admin extends User {
    constructor(name, age, email, role) {
        super(name,age,email);
        this._role = role;
    }

    get role() {
        return this._role;
    }

    set role(newRole) {
        this._role = newRole;
    }
}

const jeff = new User("Jess", 30, "jeff@gmail.com");
//const sara = new User("Sara", 23, "sara@gmail.com");
const bob = new User("Bob", 40, "bob@gmail.com");
//jeff.increaseAge();
//console.log(jeff.age)

//jeff.staticMethod();//returns TypeError
//User.staticMethod();//output "I am a static method"

//Promise, Async/Await, Callbacks, DB, API

//works if no setter and getter
//jeff.name = "Jim";
//console.log(jeff.name)

//setter and getter with encapsulation
//jeff.name = "Jeff"
//console.log(jeff.name)
//jeff.getAPI();

const sara = new Admin("Sara", 30, "sara@gmail.com", "Admin")
console.log(sara.name);
console.log(sara.role);



//  var promise = new Promise(function (resolve, reject) {
//  	resolve(Math.PI);
//  	reject(0);				//does nothing
//  	resolve(Math.sqrt(-1)); //does nothing
//  });

//  promise.then(function (number) { //that param is what the promise holds
//  	console.log('The number is ' + number);
//  });

// console.log(promise);
// console.log(promise.PromiseValue);

 //console output it
 //3.14...

 //jeff.forLoops();


 //https://medium.com/@luke_smaki/javascript-es6-classes-8a34b0a6720a