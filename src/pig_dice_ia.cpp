Action next_action_ia(){
	if(roll_dice(10)%2==0)
		return hold;
	else
		return roll;
}