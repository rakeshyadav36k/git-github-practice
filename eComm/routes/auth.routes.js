/**
 * POST localhost:8080/ecomm/api/v1/auth/signup
 * POST 127.0.0.1:8080/ecomm/api/v1/auth/signup
 * 
 * I need to intercept this
 */

const authController = require('../controllers/auth.controller')

module.exports = (app)=>{
    app.post("/ecomm/api/v1/auth/signup", authController);
}