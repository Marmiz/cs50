
<?php
    // configuration
    require("../includes/config.php"); 
    
    $rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => number_format($stock["price"], 2),
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => number_format(($row["shares"] * $stock["price"]), 2)
            ];
        }
    }
    
    $users = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "users" => $users]);
?>
