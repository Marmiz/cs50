<?php
    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        
        if ($stock !== false)
        {
            render("quote.php", ["title" => "Quote"]);
        }
        
        else
        {
            apologize("Invalid quote.");
        }
    }
    // render quote_form
    else
    {
        render("quote_form.php", ["title" => "Quote"]);
    }
?>
