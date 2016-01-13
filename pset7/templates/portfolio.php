
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
                <th>Name</th>
                <th>Symbol</th>
                <th>Shares</th>
                <th>Price</th>
                <th>Total</th>
            </tr>
        </thead>
    <?php
        foreach ($positions as $position)
        {
            print("<tr>");
            print("<td>{$position["name"]}</td>");
            print("<td>{$position["symbol"]}</td>");
            print("<td>{$position["shares"]}</td>");
            print("<td>\${$position["price"]}</td>");
            print("<td>\${$position["total"]}</td>");
            print("</tr>");
        }
    ?>
    <tr>
        <td colspan = "4"><strong>CASH</strong></td>
        <td>$<?=number_format($users[0]["cash"], 2)?></td>
    </tr>
    </table>
</div>
         
</table>
<div>
    <a href="logout.php">Log Out</a>
    <br />
    <a href="reset.php">Reset Password</a>
</div>
