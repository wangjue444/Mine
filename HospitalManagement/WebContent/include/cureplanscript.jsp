<script src="../assets/js/jquery-1.2.6.js" type="text/javascript"></script>
 <script type="text/javascript">
	function OnDelete()
	{
		
		document.form.action="todelete.do";
		var planid=document.getElementById("planid").value;
		
	
		if(planid==null||planid=="")
			return;
		
		document.form.submit();
	}
	

	function OnSelect()
	{
		
		document.form.action="toselect.do";
		var id=document.getElementById("planid").value;
		
		
		if(planid==null||planid=="")
			return;
		
		document.form.submit();
	}


	function OnUpdate()
	{
		
		document.form.action="toupdate.do";
		var planid=document.getElementById("planid").value;
		
		
		if(planid==null||planid=="")
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
				
				$("input[name=planid]").attr("value",tds.html());
				$("input[name=time]").attr("value",tds.next().html());
				$("input[name=event]").attr("value",tds.next().next().html());
				$("input[name=howoften]").attr("value",tds.next().next().next().html());
				$("input[name=details]").attr("value",tds.next().next().next().next().html());
				$("input[name=patientid]").attr("value",tds.next().next().next().next().next().html());
		 });    
			
		 
	 });
	 


 
 </script>