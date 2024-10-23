const category_model = require('../models/category.model')

/**
 * controller for creating the category
 * 
 * POST 127.0.0.1:8080/ecomm/api/v1/categories
 */

exports.createNewCategory = (req, res) =>{
    // read the request body
    const request_body = req.body

    //create the category object
    const cat_data = {
        name : request_body.name,
        discription : request_body.discription
    }

    try {
        // insert into mongodb
        const category = category_model.create(cat_data)
        return res.status(201).send(category)

    } catch (err) {
        console.log("Error while creating the category");
        return res.status(500).send({
            message : "Error while creating the category"
        })
    }

    //return the response of created category  
}