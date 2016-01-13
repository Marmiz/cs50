<div>
<ul class="nav nav-justified">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>
</div>
<?php  
       
    $stock = lookup($_POST["symbol"]);
    
    print("A share of {$stock['name']} ({$stock['symbol']}) costs: <b>$" . number_format($stock["price"], 2)); 
?>
