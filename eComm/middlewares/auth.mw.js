const user_model = require('../models/user.model')
const auth_config = require('../configs/auth.config')
/**
 * Create a mw will check if the request body is proper and correct
 */

const verifySignUpBody = async (req, res, next) =>{
    try {
        // check for name
        if(!req.body.name){
            return res.status(400).send({
                message : "Failed! name was not provided in the request body"
            })
        }

        //check for email
        if(!req.body.email){
            return res.status(400).send({
                message : "Failed! Email was not provided in the request body"
            })
        }

        //check for userid
        if(!req.body.userId){
            return res.status(400).send({
                message : "Failed! userId was not provided in the request body"
            })
        }

        //check if the user with same userid is already present
        const user = await user_model.findOne({userId : req.body.userId})

        if(user){
            return res.status(400).send({
                message : "Failed! user with the same userId is already present"
            })
        }

        next()

    } catch (err) {
        console.log("Error while validating the request object", err);
        res.status(500).send({
            message : "Error while validating the request body"
        })
    }
}


const verifySignInBody = (req, res, next)=>{
    if(!req.body.userId){
        return res.status(400).send({
            message : "UserId is not provided"
        })
    }

    if(!req.body.password){
        return res.status(400).send({
            message : "Password is not provided"
        })
    }

    next()
}

const verifyToken = (req, res, next) =>{
    // check if token is present in the header
    const token = req.header['x-access-token']

    if(!token){
        return res.status(403).send({
            message : "No token found : Unauthorized"
        })
    }
    // if it is the valid token
    jwt.verify(token, auth_config.secret, async (err, decoded) =>{
        if(err){
            return res.status(401).send({
                message : "Unauthorized"
            })
        }

        const user = await user_model.findOne({userId : decoded.id})
        if(!user){
            return res.status(400).send({
                message : "Unauthorized, this user for this token does't exits"
            })
        }

        // set the user info in the req body
        req.user = user

        next()
    })
}

const isAdmin = (req, res, next) =>{
    const user = req.user
    if(user && user.userType == "ADMIN"){
        next()
    }else{
        return res.status(403).send({
            message : "Only admin users are allowed to access this endpoints"
        })
    }
}

module.exports = {
    verifySignUpBody : verifySignUpBody,
    verifySignInBody : verifySignInBody,
    verifyToken : verifyToken,
    isAdmin : isAdmin
}