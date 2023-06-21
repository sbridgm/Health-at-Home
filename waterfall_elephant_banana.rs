// This program is intended to help people find healthy meals that can be made at home with simple ingredients. 

//1. Imports
use std::vec::Vec;

//2. Create structs
struct Ingredient {
    name: String,
    quantity: i64,
    measurement: String,
}

struct Meal {
    name: String,
    ingredients: Vec<Ingredient>,
}

//3. Create functions
//3.1 Add Ingredient to a meal
fn add_ingredient_to_meal(meal: &mut Meal, ingredient: Ingredient) {
    meal.ingredients.push(ingredient);
}

//3.2 Create a meal
fn create_meal(name: String) -> Meal {
    Meal {
        name,
        ingredients: Vec::new(),
    }
}

//3.3 Find a healthy meal
fn find_healthy_meal(meals: &[Meal], healthiness_level: i64) -> Vec<Meal> {
    let mut healthy_meals = Vec::new();

    for meal in meals {
        let healthiness_score = calculate_meal_healthiness(meal);

        if healthiness_score >= healthiness_level {
            healthy_meals.push(meal.clone());
        }
    }

    healthy_meals
}

//3.4 Calculate meal healthiness
fn calculate_meal_healthiness(meal: &Meal) -> i64 {
    let mut healthiness_score = 0;

    for ingredient in &meal.ingredients {
        let ingredient_healthiness = calculate_ingredient_healthiness(ingredient);

        healthiness_score += ingredient_healthiness;
    }

    healthiness_score
}

//3.5 Calculate ingredient healthiness
fn calculate_ingredient_healthiness(ingredient: &Ingredient) -> i64 {
    // Get the ingredient healthiness score from a database
    let healthiness_score = get_ingredient_healthiness(ingredient);
    healthiness_score
}

//3.6 Get ingredient healthiness
fn get_ingredient_healthiness(ingredient: &Ingredient) -> i64 {
    // Get healthiness score from a database
    let healthiness_score = 0;
    healthiness_score
}

//4. Main function
fn main() {
    let mut meal1 = create_meal(String::from("Chicken and Rice"));
    let ingredient1 = Ingredient {
        name: String::from("Chicken"),
        quantity: 1,
        measurement: String::from("lbs"),
    };
    add_ingredient_to_meal(&mut meal1, ingredient1);

    let mut meal2 = create_meal(String::from("Salad"));
    let ingredient2 = Ingredient {
        name: String::from("Lettuce"),
        quantity: 2,
        measurement: String::from("cups"),
    };
    add_ingredient_to_meal(&mut meal2, ingredient2);

    let meals = vec![meal1, meal2];

    let healthy_meals = find_healthy_meal(&meals, 5);
    println!("Here are some healthy meals you can make at home:");

    for meal in &healthy_meals {
        println!("{}", meal.name);
    }
}