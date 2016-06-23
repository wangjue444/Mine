<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 	<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
 	
 	
 	
<!DOCTYPE html>
<html lang="en">
  <head>
	
	<%@ include file="../include/examscript.jsp" %>
  	
    <meta charset="utf-8">
    <title>Base · Bootstrap</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content=""> 

    <!-- Le styles -->
    <link href="../assets/css/bootstrap.css" rel="stylesheet">
    <link href="../assets/css/bootstrap-responsive.css" rel="stylesheet">
    <link href="../assets/css/docs.css" rel="stylesheet">
    <link href="../assets/js/google-code-prettify/prettify.css" rel="stylesheet">

    <!-- Le HTML5 shim, for IE6-8 support of HTML5 elements -->
    <!--[if lt IE 9]>
      <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->

    <!-- Le fav and touch icons -->
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="../assets/ico/apple-touch-icon-144-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="../assets/ico/apple-touch-icon-114-precomposed.png">
      <link rel="apple-touch-icon-precomposed" sizes="72x72" href="../assets/ico/apple-touch-icon-72-precomposed.png">
                    <link rel="apple-touch-icon-precomposed" href="../assets/ico/apple-touch-icon-57-precomposed.png">
                                   <link rel="shortcut icon" href="../assets/ico/favicon.png">
   

  </head>

  <body data-spy="scroll" data-target=".bs-docs-sidebar">

    
<jsp:include page="../include/top.jsp"/>

  <div class="container">

    <!-- Docs nav
    ================================================== -->
  		<jsp:include page="../include/examleft.jsp"></jsp:include>
      
      <div class="span9">
      		<table id="maintable" class="table table-hover">
      			<thead>
      			
      			<tr>
      			
      				<th>记录编号</th>
      				<th>病人编号</th>
      				<th>时间</th>
      				<th>呼吸</th>
      				<th>脉搏</th>
      				<th>体温</th>
      				<th>血压</th>
      				
      		
      			</tr>
      			</thead>
      			<tbody>
      			    <c:forEach var="exam" items="${list}">
      			    
      			    <tr>
      			    	<td>${exam.id}</td>
      			    	<td>${exam.patientid}</td>
      			    	<td>${exam.time}</td>
      			    	<td>${exam.breath}</td>
      			    	<td>${exam.pluse}</td>
      			    
      			    	<td>${exam.temperature}</td>
      			    	<td>${exam.bloodpressure}</td>
      			    </tr>
      		
      			    </c:forEach>
      			    <tr>
      			   	<td> <button class="btn btn-large btn-primary" onclick="window.open('mail.jsp')">发送到邮箱</button></td>
      			    </tr>
      			</tbody>
      		</table>
       
        	<form id="form" name="form" hidden="true" method="post">
        		<input type="text" id="id" name="id"/>
        		<input type="text" id="patientid" name="patientid"/>
        		<input type="text" id="time" name="time"/>
        		<input type="text" id="breath" name="breath"/>
        		<input type="text" id="pluse" name="pluse"/>
        		
        		<input type="text" id="temperature" name="temperature"/>
        		<input type="text" id="bloodpressure" name="bloodpressure"/>
        	</form>

    </div>

  </div>



    <!-- Footer
    ================================================== -->
   

<jsp:include page="../include/footer.jsp"></jsp:include>

    
	
	 

  </body>
</html>