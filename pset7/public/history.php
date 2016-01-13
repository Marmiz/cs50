<?php
	//configuration
	require ("../includes/config.php");

	$table = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);

	render("history_form.php", ["title"=>"History", "table"=>$table]);


?>
