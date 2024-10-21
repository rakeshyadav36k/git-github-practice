const mongoose = require('mongoose')
const studentModel1 = require("./models/student.model1")

/**
 * write the code to connect with MongoDB
 */

mongoose.connect("mongodb://127.0.0.1/be_practiceDB")

const db = mongoose.connection // start the connection with mongodb

// after starting the the connection with mongodb, check whether it is success or failure

/**
 * error handling
 */

db.on("error", ()=>{                                   // if it is failure, it throws a event called "error"
    console.log("Error while connecting with mongoDB")
})

// if it is successful
db.once("open", ()=>{    // if there is success, it htrows a event called 'open'
    console.log("Connected to mongoDB");
    // Logic to insert the data into the database
    // init()
    
})


// function init(){
//     // Logic to insert data in the db
//     const student = {
//         name : "Rakesh"
//     }
// }