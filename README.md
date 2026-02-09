<!DOCTYPE html> 
<html> 
<head>

  <meta name=”keywords” content=”beginning html,learning″ />
  <meta name=”description” content=”A beginning web page for Web programming class” />
  
	 <<style>
:root {
    --main-gradient: linear-gradient(to bottom, #6a00ff, #000000);
    --text-color: lightblue;
}

body {
    margin: 0;
    background: var(--main-gradient);
    color: var(--text-color);
}

.container {
    display: flex;
    justify-content: space-between;
    align-items: flex-start;
    padding: 200px 200px;
}

.lefttext { text-align: left; }
.centertext { text-align: center; }
.righttext { text-align: right; }
</style>

</head>

	<body bgcolor="black" text="lightblue"> 

<div class="container">
    <div id="left" class="lefttext">
        <i><h3>EAT-BOX</h3></i>
    </div>

    <div id="content" class="centertext">
        <titre><h1>Menu</h1></titre>
    </div>

    <div id="right" class="righttext">
        <img src="food.jpg" alt="food image" width="200" height="200"/>
    </div>
</div>

</body>

</html>
