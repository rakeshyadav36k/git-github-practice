const category_controller = require('../controllers/category.controller')

/**
 * POST 127.0.0.1:8080/ecomm/api/v1/categories
 */

module.exports = (app)=>{
    app.post("/ecomm/api/v1/categories", category_controller.createNewCategory)
}
