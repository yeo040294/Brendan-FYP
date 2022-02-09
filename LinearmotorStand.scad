// radius of the circle of balls (average between external and internal radiuses)


//ball bearing stand
//stand();

// linear motor stand
//linear_motor();


// test cylinder
/*
translate([1,0,1])
rotate([90,90,0])
cylinder(2,d=2);*/
//translate([-5,-5,0])
//stand();
translate([25,25,0])
linear_motor();


//rotate([0,0,90])
//translate([-5,-5,0])
//stand();
rotate([0,0,90])
translate([25,25,0])
linear_motor();


//rotate([0,0,180])
//translate([-5,-5,0])
//stand();
rotate([0,0,180])
translate([25,25,0])
linear_motor();


//rotate([0,0,270])
//translate([-5,-5,0])
//stand();
rotate([0,0,270])
translate([25,25,0])
linear_motor();

module stand() {
difference()
{
    stand_width = 20;
    stand_height = 107;
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


module linear_motor() {
    base_width = 60;
    base_height = 3;
    thickness = 3;
    motor_width = 30.5;
    motor_depth = 38.5;
    motor_height = 64;
    linear_height = 38.5;  //default 52.5
    
    back_piston_deep = 37;
    back_piston_width = 15;
    
    padded_width = motor_width+thickness;
    padded_depth = motor_depth+thickness;
    
    difference() {
        union() {
            
            // base
            translate([-1,0,0])
            cube([base_width, base_width, base_height]);
            //x-thickness-1.5, y -1.5
            // linear motor base
            translate([(base_width-padded_width)/2-thickness-1.5,(base_width-padded_depth)/2-1.5,0])
            cube([padded_width+1.5+thickness+1.5,padded_depth+1.5+1.5,linear_height]);
            
            // holder 
            // y -1.5mm
            translate([(base_width-padded_width)/2-1.5-thickness,(base_width-padded_depth)/2-1.5,linear_height])
            cube([padded_width+1.5+1.5+thickness,thickness,motor_height]);
            //x-thickness Add 1.5mm
            translate([(base_width-padded_width)/2-thickness-1.5,(base_width-padded_depth)/2,linear_height])
            cube([thickness,padded_depth,motor_height]);
            //side y add 1.5mm
            translate([(base_width-padded_width)/2-thickness-1.5,(base_width-padded_depth)/2+motor_depth+1.5,linear_height])
            cube([padded_width+1.5+thickness+1.5,thickness,motor_height]);
            //x +1.5mm with the hole
            translate([(base_width-padded_width)/2+motor_width+1.5,(base_width-padded_depth)/2,linear_height])
            cube([thickness,padded_depth,motor_height]);
        }
        
        // screws
        
        translate([7*base_width/8,7*base_width/8,-base_height])
            cylinder(10,d=4);
        translate([1*base_width/8-2,7*base_width/8,-base_height])
            cylinder(10,d=4);
       translate([1*base_width/8-2,1*base_width/8,-base_height])
            cylinder(10,d=4);
       translate([7*base_width/8,1*base_width/8,-base_height])
            cylinder(10,d=4);
        
        // hole for piston back
        translate([(base_width)/2-1,base_width/2-1,linear_height-back_piston_deep])
            cylinder(back_piston_deep, d=back_piston_width+2);
        
        // screw holes linear motor
        /*
        translate([(base_width-padded_width)/2+5+1,(base_width-padded_depth)/2+thickness,linear_height+19.5+1])
        rotate([90,90,0])
            cylinder(thickness,d=3);
        
        translate([(base_width-padded_width)/2+17+1,(base_width-padded_depth)/2+thickness,linear_height+4.5+1])
        rotate([90,90,0])
            cylinder(thickness,d=3);*/
            
        // hole 
        translate([(base_width-padded_width)/2+motor_width+1.5,(base_width-10)/2,linear_height])
            cube([thickness,10,10]);
    }
}
