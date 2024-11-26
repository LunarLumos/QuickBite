#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISHES_FILE "dishes.txt"
#define ORDERS_FILE "orders.txt"
#define ADMIN_USERNAME="admin"
#define ADMIN_PASSWORD="password123"
// main functionalitys

//check if an order exist
void order_exists(){
    system("sh -c ' order_id=$1;
    if grep -q "^$order_id," "$ORDERS_FILE"; then
        return 0
    else
        return 1
    fi' ")
}

// Function to cancel an order
void cancel_order(){
    system("sh -c '    echo "Enter the Order ID to cancel (e.g., O1, O2, O3):"
    read order_id

    order_id=$(echo "$order_id" | xargs)


    if [[ ! "$order_id" =~ ^O ]]; then
        order_id="O$order_id"
    fi


    if ! order_exists "$order_id"; then
        echo "Error: Order ID $order_id not found!"
        return
    fi

    # Mark the order as canceled
    sed -i "s/^$order_id,.*/$order_id,*,*,*,*,*,*,*,Canceled/" "$ORDERS_FILE"
    echo "Order $order_id canceled successfully!" '";
    
}

//display all orders
void display_orders() {
    system("sh -c '    if [ ! -f "$ORDERS_FILE" ]; then
        echo "Error: No orders found!"
        return
    fi

    echo "All Orders:"
    while IFS=, read -r order_id customer_name customer_address customer_phone dish_id dish_name quantity total_cost status; do
        echo "Order ID: $order_id | Customer: $customer_name | Dish: $dish_name | Quantity: $quantity | Total: $total_cost tk | Status: $status"
    done < "$ORDERS_FILE"'");
}


// Display all dishes
void display_dishes() {

    system("sh -c 'if [ ! -f " DISHES_FILE " ]; then "
           "echo \"Error: No dishes available. The menu is empty!\"; "
           "else "
           "echo \"All available dishes:\"; "
           "while IFS=, read -r dish_id dish_name dish_description dish_price dish_prep_time; do "
           "echo \"Dish ID: $dish_id | Name: $dish_name | Price: $dish_price tk | Time: $dish_prep_time min\"; "
           "done < " DISHES_FILE "; "
           "fi'");
}

// search for dishes by name
void search_dishes(){
    system("sh -c '    echo "Enter dish name to search for (part of name):"
    read search_term

    found=0

    while IFS=, read -r dish_id dish_name dish_description dish_price dish_prep_time; do
        if [[ "${dish_name,,}" == *"${search_term,,}"* ]]; then
            echo "Dish ID: $dish_id | Name: $dish_name | Price: $dish_price tk | Time: $dish_prep_time min"
            found=1
        fi
    done < "$DISHES_FILE"

    if [ $found -eq 0 ]; then
        echo "No dishes found matching '$search_term'."
    fi'")

}

//# add a new dish
void add_dish(){
    system("sh -c '    echo "Enter Dish ID (e.g., 1, 2, 3):"
    read dish_id
    echo "Enter Dish Name:"
    read dish_name
    echo "Enter Dish Description:"
    read dish_description
    echo "Enter Dish Price (in tk):"
    read dish_price
    echo "Enter Dish Preparation Time (in minutes):"
    read dish_prep_time

    # Save the new dish to the dishes file
    echo "$dish_id,$dish_name,$dish_description,$dish_price,$dish_prep_time" >> "$DISHES_FILE"
    echo "Dish '$dish_name' added successfully!" ' ");
}

//update a dish
void update_dish(){
    system("sh -c '     echo "Enter the Dish ID to update (e.g., 1, 2, 3):"
    read dish_id

    # Check if the dish exists
    dish_info=$(grep "^$dish_id," "$DISHES_FILE")
    if [ -z "$dish_info" ]; then
        echo "Error: Dish not found!"
        return
    fi

    echo "Enter new Dish Name (or press Enter to keep the current):"
    read dish_name
    if [ -z "$dish_name" ]; then
        dish_name=$(echo "$dish_info" | cut -d ',' -f 2)
    fi

    echo "Enter new Dish Description (or press Enter to keep the current):"
    read dish_description
    if [ -z "$dish_description" ]; then
        dish_description=$(echo "$dish_info" | cut -d ',' -f 3)
    fi

    echo "Enter new Dish Price (or press Enter to keep the current):"
    read dish_price
    if [ -z "$dish_price" ]; then
        dish_price=$(echo "$dish_info" | cut -d ',' -f 4)
    fi

    echo "Enter new Dish Preparation Time (or press Enter to keep the current):"
    read dish_prep_time
    if [ -z "$dish_prep_time" ]; then
        dish_prep_time=$(echo "$dish_info" | cut -d ',' -f 5)
    fi

    # Update the dish in the dishes file
    sed -i "s/^$dish_id,.*/$dish_id,$dish_name,$dish_description,$dish_price,$dish_prep_time/" "$DISHES_FILE"
    echo "Dish '$dish_name' updated successfully!" '")
}

//# delete a dish

void delete_dish(){
    system("sh -c '    echo "Enter the Dish ID to delete (e.g., 1, 2, 3):"
    read dish_id

    if ! grep -q "^$dish_id," "$DISHES_FILE"; then
        echo "Error: Dish not found!"
        return
    fi

    # Delete the dish
    sed -i "/^$dish_id,/d" "$DISHES_FILE"
    echo "Dish with ID $dish_id deleted successfully!" '");
}


int main() {
    display_dishes();
    return 0;
}
