const mongoose = require('mongoose')

/**
 * name
 * userId
 * password
 * email
 * usertype
 */

const userSchema = new mongoose.Schema({
    name : {
        type : String,
        required : true
    },
    userId : {
        type : String,
        required : true,
        unique : true
    },
    password : {
        type : String,
        required : true
    },
    email : {
        type : String,
        required : true,
        minLength : 10,
        unique : true
    },
    userType : {
        type : String,
        required : true,
        default : "CUSTOMER",
        enum : ["CUSTOMER", "ADMIN"]
    }
}, {versionKey : false, timestamps : true})

module.exports = mongoose.model("User", userSchema)