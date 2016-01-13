<?php
	//configuration
	require ("../includes/config.php");

	if ($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$stock = lookup($_POST["symbol"]);
		$shares = query( "SELECT shares FROM portfolio WHERE id=? AND symbol=?", $_SESSION["id"], $_POST["symbol"]);
		$value = $stock["price"] * $shares[0]["shares"];
		$transaction = 'SELL';

		query("UPDATE users SET cash = cash + ? where id = ?", $value, $_SESSION["id"]);
        
        	query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        	query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["symbol"], $shares, $stock["price"]);

        	redirect("/");
	}

	else
    	{
        $rows = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);
        
        $stocks = [];
        
        foreach($rows as $row)
        	{
            	$stock = $row["symbol"];
            
           	$stocks[] = $stock;
       		}
        
        render("sell_form.php", ["title" => "Sell Form", "stocks" => $stocks]);
        
   	}


?>
