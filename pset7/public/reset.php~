<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("reset_form.php", ["title" => "Reset"]);
    }


    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

	
	//sanity checks	  
      

	if(empty($_POST["password"]))
	{
		apologize("password is required");
	}

	else if($_POST["password"] != $_POST["confirmation"])
	{
		apologize("the passwords does not match");
	}
	
	else
	{
		//update password into database
		query("UPDATE users SET hash = ? WHERE id =?",crypt($_POST["password"]), $_SESSION["id"]);
		redirect("index.php");
		

	}
    }

?>
