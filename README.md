# QuickBite - Food Delivery Management System

**QuickBite** is a food delivery management system designed to automate order processing and menu management for **Delicious Eats** restaurant. This system was developed as part of the **Structured Programming with Lab (CIS 122 & 122L)** course at **Department of Computing and Information Systems**, **Daffodil International University**.

## Course Information
- **Course Title**: Structured Programming with Lab
- **Course Code**: CIS 122 & 122L
- **Instructor**: [Instructor Name]
- **Department**: Department of Computing and Information Systems
- **University**: Daffodil International University

## Features

### Admin Panel:
- **Add New Dishes**: Add dishes to the menu with name, description, price, and preparation time.
- **Modify Dishes**: Update details of existing dishes.
- **Delete Dishes**: Remove dishes from the menu.
- **View Dishes**: Display all available dishes.
- **Search Dishes**: Search dishes by name.
- **Sales Report**: View total sales and order details.

### Customer Panel:
- **View Dishes**: Browse all dishes on the menu.
- **Place Orders**: Order dishes by specifying quantity.
- **Cancel Orders**: Cancel previously placed orders.
- **View Orders**: View details of orders placed.
- **Search Dishes**: Search for specific dishes.

## Implementation Details

The system is built using **Bash scripting** with **file handling** to manage data:

- **Data Structures**: Dishes and orders are represented using structures.
  - Dishes include details like name, description, price, and preparation time.
  - Orders store customer details (name, address, contact), the ordered dish, and status.
  
- **Files**:
  - `dishes.txt`: Stores dish information.
  - `orders.txt`: Stores customer order details.

The system reads and writes to these text files to store and manage data.

## Requirements
- Bash shell (Linux/macOS terminal)
- Text editor (to modify the script)

## Usage

### Admin Login:
- **Username**: `admin`
- **Password**: `password123`

### Admin Functions:
- Add, update, or delete dishes.
- View and search dishes.
- View sales report.

### Customer Functions:
- Browse dishes, place orders, cancel orders.
- View placed orders.
- Search for dishes.

## File Format Example

### Dishes (dishes.txt):
```txt
1,Pasta,Delicious Italian pasta,300,15
2,Burger,Classic American burger,150,10
```

### Orders (orders.txt):
```txt
O101,John Doe,123 Main St,1234567890,1,Pasta,2,600,Pending
O102,Jane Smith,456 Elm St,0987654321,2,Burger,1,150,Pending
```

## Limitations
- **Security**: Basic password handling with no encryption.
- **Scalability**: Data is stored in text files, which may not be efficient for large-scale systems.

## License
This is a semester project and is for educational purposes only. It is not intended for commercial use.

## Contact
For questions or suggestions, contact the developer:  
[Aadil](https://github.com/LunarLumos)
