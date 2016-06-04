void makeAction (Game g, action a) {
   int uni = getWhoseTurn(g);
   arc finalPos = finalPosition(a.destination, g);
   int index = 0;
          
   if (a.actioncode == PASS){
   }else if (a.actionCode == BUILD_CAMPUS) {
      g->studentType[uni].bPs--;
      g->studentType[uni].bQn--;
      g->studentType[uni].mJ--;
      g->studentType[uni].mTV--;
      index = coordinateToVertex(finalPos.end);
      g->vertex[index] = uni;
   }else if (a.actionCode == BUILD_GO8) {
      g->studentType[uni].mJ -= 2;
      g->studentType[uni].mMoney -= 3;
      index = coordinateToVertex(finalPos.end);
      g->vertex[index] = uni + NUM_UNIS;
   }else if (a.actionCode == OBTAIN_ARC) {
      g->studentType[uni].bPs--;
      g->studentType[uni].bQn--;
      index = coordinateToArc(finalPos);
     g->arcs[index] = uni;
   }else if (a.actionCode == OBTAIN_PUBLICATION) {
     g->studentType[uni].mJ--;
     g->studentType[uni].mTV--;
     g->studentType[uni].mMoney--;
     g->playerState[uni].publication++;
   }else if (a.actionCode == OBTAIN_IP_PATENT) {
     g->studentType[uni].mJ--;
     g->studentType[uni].mTV--;
     g->studentType[uni].mMoney--;
     g->playerState[uni].ip++;
   }else if (a.actionCode == RETRAIN_STUDENTS) {
      if (a.disciplineFrom == STUDENT_BPS) {
         g->studentType[uni].bPs -= getExchangeRate(g, uni, a.disciplineFrom, a.disciplineTo);
      } else if (a.disciplineFrom == STUDENT_BQN) {
         g->studentType[uni].bQn -= getExchangeRate(g, uni, a.disciplineFrom, a.disciplineTo);
      } else if (a.disciplineFrom == STUDENT_MJ) {
         g->studentType[uni].mJ -= getExchangeRate(g, uni, a.disciplineFrom, a.disciplineTo);
      } else if (a.disciplineFrom == STUDENT_MTV) {
         g->studentType[uni].mTV -= getExchangeRate(g, uni, a.disciplineFrom, a.disciplineTo);
      } else if (a.disciplineFrom == STUDENT_MMONEY) {
         g->studentType[uni].bQn -= getExchangeRate(g, uni, a.disciplineFrom, a.disciplineTo);
      }
      if (a.disciplineTo == STUDENT_THD) {
         g->studentType[uni].thD++; // uni recieves retrained student
      } else if (a.disciplineTo == STUDENT_BPS) {
         g->studentType[uni].bPs++;
      } else if (a.disciplineTo == STUDENT_BQN) {
         g->studentType[uni].bQn++;
      } else if (a.disciplineTo == STUDENT_MJ) {
         g->studentType[uni].mJ++;
      } else if (a.disciplineTo == STUDENT_MTV) {
         g->studentType[uni].mTV++;
      } else if (a.disciplineTo == STUDENT_MMONEY) {
         g->studentType[uni].mMoney++;
      }
   }

   if(getMostARCs(g) == NOBODY){
      if(g->uni[A] != 0){
         g->mostARCs = UNI_A;
      } else if (g->uni[B] != 0){
         g->mostARCs = UNI_B;
      } else if (g->uni[C] != 0){
         g->mostARCs = UNI_C;
      } 
   } else {
      if(getARCs(g, getMostARCs(g)) < getARCs(g, UNI_A) ||
         getARCs(g, getMostARCs(g)) < getARCs(g, UNI_B) ||
         getARCs(g, getMostARCs(g)) < getARCs(g, UNI_C)){
         g->mostARCs = uni;
      }
   } 
}