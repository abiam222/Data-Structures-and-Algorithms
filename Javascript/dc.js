main()

function main() {
    let elem1 = {
        "one": 1,
        "two": 2,
        "three": 3,
        "five": 5
    }

    let elem2 = {
        "one": 1,
        "two": 2,
        "three": 1,
        "four": 4,
        "five": 8
    }
    
    let vals = new Map();
    Object.entries(elem1).forEach((x,y)=>{
        //if has set , if doesnt' set default
        if (vals.has(x[0])) {
            let tmp = vals.get(x[0]);
            tmp.push(x[1]);
            vals.set(x[0], tmp);
        } else {
            vals.set(x[0],[x[1]]);
        }

    })
    
    Object.entries(elem2).forEach((x,y)=>{
        //if has set , if doesnt' set default
        if (vals.has(x[0])) {
            let tmp = vals.get(x[0]);
            tmp.push(x[1]);
            vals.set(x[0], tmp);
        } else {
            vals.set(x[0],[x[1]]);
        }
    })
    let farr =[];
    let obj3={};
    let obj4={};
    //if vals has values that are either different or different length add
    vals.forEach((x,y)=>{
        if (x.length == 1 || x[0]!=x[1]) {
            obj3[y]=x[0];
            farr.push(Object.assign({},obj3))
                
            obj4[y]=x[1] || "" ;
            farr.push(Object.assign({},obj4))
               
            delete obj3[y];
            delete obj4[y];
        }
    })
    console.log('farr')
    console.log(farr)
    console.log()
    //final [{"three": 3},{"three":1},{"four":4},{"four":""}{"five:5"},{"five":8}]

    let finalarr=[];
    let finalarrSet= new Set();
    let obj={};
    let obj2={};
    let k=0;

    for (let [key, value] of Object.entries(elem1)) {
        for (let [key2, value2] of Object.entries(elem2)) {
            if (key==key2 && value!=value2){

                //we use Object.assing(...) because it doesn't
                //copy by reference. Makes an actual copy, if not
                //when we later change obj[key] it will change it for us

                obj[key]=value;
                finalarr.push(Object.assign({},obj))
                finalarrSet.add(Object.assign({},obj))
                
                obj2[key2]=value2;//this changes, points
                finalarr.push(Object.assign({},obj2))
                finalarrSet.add(Object.assign({},obj2))
               
                //doing this because if you don't it 
                //keeps adding the previous values so in our example
                //we will now have {"three":3, "five":5},
                //instead of separe values
                delete obj[key];
                delete obj2[key];

                //might not work with for of ...
                break;//because it found what all I want, I don't have to continue itr
            }
        } 
    }

    for (let [key, value] of Object.entries(elem2)) {
        for (let [key2, value2] of Object.entries(elem1)) {
            // console.log(key)
            // console.log(value)
            // console.log(key2)
            // console.log(value2)
            // console.log()
            k++;
            if ( (key==key2 && value!=value2) ) k=-1;

            if ( (key==key2 && value!=value2) || ( k==elem1.length ) ) {
                k=-1;
                //we use Object.assing(...) because it doesn't
                //copy by reference. Makes an actual copy, if not
                //when we later change obj[key] it will change it for us

                obj[key]=value;
                finalarr.push(Object.assign({},obj))
                finalarrSet.add(Object.assign({},obj))
                
                obj2[key2]=value2;//this changes, points
                finalarr.push(Object.assign({},obj2))
                finalarrSet.add(Object.assign({},obj2))
               
                //doing this because if you don't it 
                //keeps adding the previous values so in our example
                //we will now have {"three":3, "five":5},
                //instead of separe values
                delete obj[key];
                delete obj2[key];

                //might not work with for of ...
                break;//because it found what all I want, I don't have to continue itr
            }
            k=0;
        } 
    }

    // console.log(Object.entries(elem1))//array of entries
    // console.log(Object.keys(elem1))//array of keys
    // console.log(Object.values(elem1))//array of values
    console.log(finalarr)
    console.log(finalarrSet)
}



//iterate array
//itearte through object
    //keys
    //values
    //make array of keys
    //make array of values
