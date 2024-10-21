/**
 * 1. Define the schema of the students collection to be stored in the DB
 */

const mongoose = require('mongoose')

// 2. Schema

const studentSchema = new mongoose.Schema({
    name : String,
    age : Number
})

// 3. Go ahead and create corresponding collection in DB
module.exports = mongoose.model("student", studentSchema)  // ("Name of the collection", schema of the documents)