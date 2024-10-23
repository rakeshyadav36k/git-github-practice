/**
 * I need to write the controller || logic to register a user
 */

const bcrypt = require('bcryptjs')
const user_model = require('../models/user.model')
const jwt = require('jsonwebtoken')
const secret = require('../configs/auth.config')


exports.signup = (req, res)=>{
    /**
     * Logic to create a user
     */

    // 1. read the request body

    const request_body = req.body  // in the form of JS object

    // 2. Insert the data in the users collection in the MongoDB
    const userObj = {
        name : request_body.name,
        userId : request_body.userId,
        email : request_body.email,
        userType : request_body.userType,
        password : bcrypt.hashSync(request_body.password, 8)
    }

    try{
        const user_created = user_model.create(userObj)

        /**
         * Return this user
         */
        // res.status(201).send(user_created)

        // if you don't want to sent the sensitive information (Password)
        const res_obj = {
            name : user_created.name,
            userId : user_created.userId,
            email : user_created.email,
            userType : user_created.userType,
            createdAt : user_created.createdAt,
            updatedAt : user_created.updatedAt
        }
        res.status(201).send(res_obj)

    }catch(err){
        console.log("error while registering user", err);
        res.status(500).send({
            message : "Some error happens while registering the user"
        })
    }

    // 3. return the response back to the user
}


exports.signin = async(req, res)=>{
    // check if the userid is present in the system
    const user = await user_model.findOne({userId : req.body.userId})

    if(user == null){
        return res.status(400).send({
            message : "User id passed is not a valid userId"
        })
    }

    // check if password is correct
    const isPasswordValid = bcrypt.compareSync(req.body.password, user.password) 
    if(!isPasswordValid){
        return res.status(401).send({
            message : "Wrong password is passed"
        })
    }

    // using jwt we will create a access token with a given TTL and return
    const token = jwt.sign({id : user.userId}, secret.secret, {
        expiresIn : 120
    })

    res.status(200).send({
        name : user.name,
        userId : user.userId,
        email : user.email,
        userType : user.userType,
        accessToken : token
    })
}