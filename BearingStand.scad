// radius of the circle of balls (average between external and internal radiuses)


//ball bearing stand
stand();

module stand() {
difference()
{
    stand_width = 20;
    stand_height = 117;
    base_width = 40;
    base_height = 3;
    union() {
            
       
	/*
          translate([-thickness,+7*support_length-thickness,-support_height])
          cube([2*support_length,2*support_length,support_height+support_height+2*thickness]);
    }
        */
        //stand
      
    //cube([stand_width,stand_width,stand_height]);
        translate([base_width/2, base_width/2,0]) 
        cylinder(stand_height,d = stand_width);
    
        //base
        
    //cube([base_width, base_width, base_height]);
        
        
        }
        
        // hold for middle screw
        translate([base_width/2,base_width/2,stand_height-30])
       cylinder(50,d=4);
        
        // hold for middle bottom screw
        translate([base_width/2,base_width/2,0])
       cylinder(50,d=4);
    //hold for screw
        /*
        translate([7*base_width/8,7*base_width/8,-base_height])
       cylinder(10,d=4);
        translate([1*base_width/8,7*base_width/8,-base_height])
       cylinder(10,d=4);
       translate([1*base_width/8,1*base_width/8,-base_height])
       cylinder(10,d=4);
       translate([7*base_width/8,1*base_width/8,-base_height])
       cylinder(10,d=4);*/
    
}
}
