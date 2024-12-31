const mongoose = require('mongoose')
const studentModel1 = require("./models/student.model1")

/**
 * write the code to connect with MongoDB
 */

mongoose.connect("mongodb://127.0.0.1/be_practiceDB")
// mongoose.connect("mongodb://localhost/be_practiceDB")

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
    init()

    // Running the queries on MongoDB
    dbQueries()
    
})


async function init(){
    // Logic to insert data in the db
    const student = {
        name : "Rakesh",
        age : 23,
        email : "rakeshyadav708175064@gmail.com",
        subject : ["English", "Science", "Maths"]
    }

    const std_obj = await studentModel1.create(student); // we have to wait at this step

    console.log(std_obj);
    
}

async function dbQueries(){
    // read the student data based on the id

    try{
        const student = await studentModel1.findById("6716a81133376b98b26fcb61")
        console.log(student)
    }
    catch(err){
        console.log(err);
        
    }


    // search based on the name
    try{
        // const students = await studentModel.find({name:"Rakesh"})
        // const students = await studentModel.find({})  // acts like a find all
        const students = await studentModel1.findOne({name:"Rakesh"})
        console.log(students)
    }catch(err){
        console.log(err)
    }


    /**
     * Deal with the multiple conditions
     */
    const stds = await studentModel1.where("age").gt("10").where("name").equals("Rakesh").limit(2)
    // console.log(stds)


    /**
     * Delete one documents where name = "Vishwa"
     */

    const student = await studentModel1.deleteOne({name : "Vishwa"})
    // console.log(student)
}