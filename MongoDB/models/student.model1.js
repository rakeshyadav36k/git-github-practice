/**
 * 1. Define the schema of the students collection to be stored in the DB
 */

const mongoose = require('mongoose')

// 2. Schema

const studentSchema = new mongoose.Schema({
    name : {
        type : String,
        required : true
    }, 
    age :{
        type : Number,
        min : 19
    },
    email : {
        type : String,
        required : true,
        lowercase : true,
        minLength : 12
    },

    subject : [String]

    // createdAt : {
    //     type : Date,
    //     immutable : true,
    //     default : () =>{
    //         return Date.now();
    //     }
    // }
}, {versionKey : false, timestamps : true})

// 3. Go ahead and create corresponding collection in DB

module.exports = mongoose.model("student", studentSchema)  // ("Name of the collection", schema of the documents)