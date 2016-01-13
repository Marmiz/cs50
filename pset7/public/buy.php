<?php
    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] === "POST")
    {
        if(empty($_POST["stock"]) || empty($_POST["amount"]))
        {
            apologize("Please enter a stock symbol and/or valid amount.");
        }
        
        else if(lookup($_POST["stock"]) === false)
        {
            apologize("Invalid stock symbol.");
        }
        
        else if(preg_match("/^\d+$/", $_POST["amount"]) == false)
        {
            apologize("You must enter a valid number.");
        }
        
        $transaction = 'BUY';
        
        $stock = lookup($_POST["stock"]);
        
        $cost = $stock["price"] * $_POST["amount"];
        
        $cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

	
        
        if ($cash[0]["cash"] < $cost )
        {
            apologize("You cannot afford that!");
        }
       
        else
        {
            $_POST["stock"] = strtoupper($_POST["stock"]);
            
            query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?)
                ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["stock"], $_POST["amount"]);
                
            query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);

	    query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["stock"], $_POST["amount"], $stock["price"]);
            
            redirect("/");
            
        }
        
    }
    
    else
    {
        render("buy_form.php", ["title" => "Buy Form"]);   
    }
?>
