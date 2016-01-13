
<div>
<ul class="nav nav-justified">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
</ul>
</div>
<div>
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Transaction</th>
                <th>Date/Time</th>
                <th>Symbol</th>
                <th>Shares</th>
                <th>Price</th>
            </tr>
        </thead>
        
    <tbody>
    
    <?php
        foreach ($table as $row)
        {
            print("<tr>");
            print("<td>{$row["transaction"]}</td>");
            print("<td>". date('d/m/y, g:i A', strtotime($row["date"])) ."</td>");
            print("<td>{$row["symbol"]}</td>");
            print("<td>{$row["shares"]}</td>");
            print("<td>$". number_format($row["price"], 2) ."</td>");
            print("</tr>");
        }
    ?>
    
    </tbody>
    
    </table>
</div>
