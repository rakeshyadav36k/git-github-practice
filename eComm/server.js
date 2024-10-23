/**
 * this will be starting file of the project
 */

const express = require('express')
const mongoose = require('mongoose')

const app = express()
const server_config = require('./configs/server.config')
const db_config = require('./configs/db.config')
const user_model = require('./models/user.model')
const bcrypt = require('bcryptjs')

app.use(express.json()) // middleware | when we pass request body as JSON, by using this middleware, It read as JS object


mongoose.connect(db_config.DB_URL) // connection with mongodb

const db = mongoose.connection

db.on("erroe", ()=>{
    console.log("Error while connection with mongoDB");
})

db.once("open", ()=>{
    console.log("Connected to MongoDB");
    init()
})

async function init(){
    try{
        let user = await user_model.findOne({userId : "admin"})

        if(user){
            console.log("Admin is already present");
            return;
        }
    }catch(err){
        console.log("Error while reading the data");        
    }

    // if admin is not present then insert the admin info into db

    try{
        user = await user_model.create({
            name : "Rakesh",
            userId : "admin",
            email : "rakeshyadav36k@gmail.com",
            userType : "ADMIN",
            password : bcrypt.hashSync("Welcome1", 8)  // 8 is a salt value
        })

        console.log("Admin created", user)
    }catch(err){
        console.log("Error while creating admin", err);        
    }

}


/**
 * Stich the routes to the server
 */

require('./routes/auth.routes')(app)
require('./routes/category.routes')(app)

/**
 * start the server
 */
app.listen(server_config.PORT, ()=>{
    console.log("Server has been started at port no : ", server_config.PORT);
    
})
