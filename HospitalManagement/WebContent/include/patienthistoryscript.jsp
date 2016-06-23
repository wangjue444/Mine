<script src="../assets/js/jquery-1.2.6.js" type="text/javascript"></script>
 <script type="text/javascript">
	function OnDelete()
	{
		
		document.form.action="todelete.do";
		var id=document.getElementById("id").value;
		
	
		if(id==null||id=="")
			return;
		
		document.form.submit();
	}
	

	function OnSelect()
	{
		
		document.form.action="toselect.do";
		var id=document.getElementById("id").value;
		
		
		if(id==null||id=="")
			return;
		
		document.form.submit();
	}


	function OnUpdate()
	{
		
		document.form.action="toupdate.do";
		var id=document.getElementById("id").value;
		
		
		if(id==null||id=="")
			return;
		
		document.form.submit();
	}

	 $(document).ready(function(){

		 $("#maintable tr").click(function(){
			   var tds=$(this).find("td");
			 
				var trs=$(this).parent("tbody").find("tr");
				trs.each(function(){
					$(this).css("background","#fff");
				});
				
				 $(this).css("background","#f5f5f5");
				
				$("input[name=id]").attr("value",tds.html());
				$("input[name=content]").attr("value",tds.next().html());
				$("input[name=patientid]").attr("value",tds.next().next().html());
				
		 });    
			
		 
	 });
	 


 
 </script>