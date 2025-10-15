/*********************************************************
	Function: 	selectionSort                        
	Purpose:	This function performs the selection sort     
				algorithm on hoursSM array, sorting the 
				hours in ascending order and making sure 
				to also sort the name arrays at the same 
				time.
 *********************************************************/
void selectionSort(string lastName[],string firstName[], double hoursSM[], int size)
{
	int start, minIndex;
	double minValue;
	string nameTemp;

	for (start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = hoursSM[start];
		for(int index = start + 1; index < size; index++)
		{
			if (hoursSM[index] < minValue)
			{
				minValue = hoursSM[index];
				minIndex = index;
			}
		}
		//swap hoursSM array values
		hoursSM[minIndex] = hoursSM[start];
		hoursSM[start] = minValue;
		//swap firstName array values
		nameTemp = firstName[minIndex];
		firstName[minIndex] = firstName[start];
		firstName[start] = nameTemp;
		//swap lastName array values
		nameTemp = lastName[minIndex];
		lastName[minIndex] = lastName[start];
		lastName[start] = nameTemp;
	}
}