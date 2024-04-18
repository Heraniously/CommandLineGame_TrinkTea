# CommandLineGame_TrinkTea
It is a command line game made in c, where users can interact and execute certian actions in the virtual online shop selling teas.


The program includes 1 header file, 4 C files and 2 text files.
    header.h - It accomodates all header information.
    main.C - Main File
    menu.C - It holds a function displaying the intro pixel art and a function showing the user about the choice options.
    orders.C - It handles functions that are realted to orders. That includes a function to place order and a function to view the order history.
    utility.C - It contains utilities.
    warehouse.C - 
    orders.txt - Orders placed by customers are saved.
    products.txt - Available products are listed.


Once you execute the executable file, the program introduces the user 4 options:

1 - User can place an order. 
    Once User chooses this option, the available products are displayed.
    User enters first name, last name, product number and quantity.
    If the product is sold out, the order doesn't go through.
    Once the order is placed, the total price is displayed.
    Then the order detail is saved in orders.txt and the stock quantity of the product is updated in products.txt.

2 - User can view the order history.
    The history search is based on the first name and last name of the customer. The program displays the order details, if the first name and last name match the order information.

3 - Admin can add products.
    To be able to add products, user must log in entering 'admin' for both first name and last name. Then the user can add products by typing the product name, price, quantity and  the description. The product number is given, incrementing the product number of the last product. The product is saved in products.txt.

4 - User can search products.
    First method is searching by price range by setting min and max price.
    Second method is searching by combinations of name and price, which I didn't manage to implement.


