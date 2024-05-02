
   SOIENT
       A1 , A2 , A3 , P , Q DES ARB ;
       I , M , N DES ENTIER ;
       L UN BOOLEEN ;
       Creerarb_sansdouble UNE FONCTION ( BOOLEEN ) ;
       Inserer_sans_double UNE FONCTION ( BOOLEEN ) ;
       Inserer_avec_double UNE ACTION ;
       Verifier_bst UNE FONCTION ( BOOLEEN ) ;
       Nombre_noeud UNE FONCTION ( ENTIER ) ;
       Verifier_fusion UNE FONCTION ( BOOLEEN ) ;
       Supprimer_arb UNE ACTION ;
       Suivant_inordre UNE FONCTION ( ARB ) ;
       Premier_postordre , Suivant_postordre , Suivant_preordre DES FONCTION ( ARB ) ;
       Option1 , Option2 , Option3 , Option4 , Option5 DES ACTION ;
      
   DEBUT
       M := 10 ;
       N := 50 ;
       POUR I := 1 , M
      /* Generation des arbres aleatoires */
           L := Creerarb_sansdouble ( A1 , N ) ;
           L := Creerarb_sansdouble ( A2 , N ) ;
          /* Fusion et teste 1 */
           APPEL Option1 ( A1 , A2 , A3 , P , Q ) ;
           ECRIRE ( Verifier_fusion ( A3 , 2 * N ) ) ;
           APPEL Supprimer_arb ( A3 ) ;
          /* Fusion et teste 2 */
           APPEL Option2 ( A1 , A2 , A3 , P , Q ) ;
           ECRIRE ( Verifier_fusion ( A3 , 2 * N ) ) ;
           APPEL Supprimer_arb ( A3 ) ;
          /* Fusion et teste 3 */
           APPEL Option3 ( A1 , A2 , A3 , P , Q ) ;
           ECRIRE ( Verifier_fusion ( A3 , 2 * N ) ) ;
           APPEL Supprimer_arb ( A3 ) ;
          /* Fusion et teste 4 */
           APPEL Option4 ( A1 , A2 , A3 , P , Q ) ;
           ECRIRE ( Verifier_fusion ( A3 , 2 * N ) ) ;
           APPEL Supprimer_arb ( A3 ) ;
          /* Fusion et teste 5 */
           APPEL Option5 ( A1 , A2 , A3 , P , Q ) ;
           ECRIRE ( Verifier_fusion ( A3 , 2 * N ) ) ;
           APPEL Supprimer_arb ( A3 ) ;
           APPEL Supprimer_arb ( A1 ) ;
           APPEL Supprimer_arb ( A2 ) ;
          
       FINPOUR ;
      
   FIN
  /* ---------------------------------------------------- */
  /* ---------------------------------------------------- */
  /*               LES FONCTIONS ET ACTIONS               */
  /* ---------------------------------------------------- */
  /* ---------------------------------------------------- */
  /* ---------------------------------------------------- */
  /*             Fonction Creerarb_sansdouble             */
  /* ---------------------------------------------------- */
   FONCTION Creerarb_sansdouble ( A , Nombre ) : BOOLEEN
   SOIENT
       A UN ARB ;
       Nombre , I , J DES ENTIER ;
      
   DEBUT
       I := 0 ;
       A := NIL ;
       TANTQUE I < Nombre
           J := ALEANOMBRE ( 10000 ) ;
           L := Inserer_sans_double ( A , J ) ;
           SI L = VRAI
               I := I + 1 ;
              
           FSI ;
          
       FINTANTQUE ;
       SI A <> NIL
           Creerarb_sansdouble := VRAI ;
          
       SINON
           Creerarb_sansdouble := FAUX ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*             Fonction Inserer_sans_double             */
  /* ---------------------------------------------------- */
   FONCTION Inserer_sans_double ( A , Val ) : BOOLEEN
   SOIENT
       A , Parent , Temp DES ARB ;
       Val UN ENTIER ;
      
   DEBUT
       Inserer_sans_double := VRAI ;
       Parent := NIL ;
       Temp := A ;
       TANTQUE Temp <> NIL
           Parent := Temp ;
           SI Val < INFO ( Temp )
               Temp := FG ( Temp ) ;
              
           SINON
               SI Val > INFO ( Temp )
                   Temp := FD ( Temp ) ;
                  
               SINON
                   Inserer_sans_double := FAUX ;
                   Temp := NIL ;
                  
               FSI ;
              
           FSI ;
          
       FINTANTQUE ;
       SI Inserer_sans_double <> FAUX
           CREERNOEUD ( Temp ) ;
           AFF_INFO ( Temp , Val ) ;
           SI Parent = NIL
               A := Temp ;
              
           SINON
               SI Val < INFO ( Parent )
                   AFF_FG ( Parent , Temp ) ;
                  
               SINON
                   AFF_FD ( Parent , Temp ) ;
                  
               FSI ;
              
           FSI ;
           AFF_PERE ( Temp , Parent ) ;
           Inserer_sans_double := VRAI ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                 Inserer_avec_double                  */
  /* ---------------------------------------------------- */
   ACTION Inserer_avec_double ( A , Val )
   SOIENT
       A , Parent , Temp DES ARB ;
       Val UN ENTIER ;
      
   DEBUT
       Parent := NIL ;
       Temp := A ;
       TANTQUE Temp <> NIL
           Parent := Temp ;
           SI Val <= INFO ( Temp )
               Temp := FG ( Temp ) ;
              
           SINON
               Temp := FD ( Temp ) ;
              
           FSI ;
          
       FINTANTQUE ;
       CREERNOEUD ( Temp ) ;
       AFF_INFO ( Temp , Val ) ;
       SI Parent = NIL
           A := Temp ;
          
       SINON
           SI Val <= INFO ( Parent )
               AFF_FG ( Parent , Temp ) ;
              
           SINON
               AFF_FD ( Parent , Temp ) ;
              
           FSI ;
          
       FSI ;
       AFF_PERE ( Temp , Parent ) ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                     Verifier_bst                     */
  /* ---------------------------------------------------- */
   FONCTION Verifier_bst ( A , Min_val , Max_val ) : BOOLEEN
   SOIENT
       A UN ARB ;
       Min_val , Max_val DES ENTIER ;
      
   DEBUT
       SI A = NIL
           Verifier_bst := VRAI ;
          
       SINON
           SI ( INFO ( A ) >= Min_val ) ET ( INFO ( A ) <= Max_val ) ET ( Verifier_bst ( FG ( A ) , Min_val , INFO ( A
           ) ) ) ET ( Verifier_bst ( FD ( A ) , INFO ( A ) + 1 , Max_val ) )
               ;
               Verifier_bst := VRAI ;
              
           SINON
               Verifier_bst := FAUX ;
              
           FSI ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                    Nombre_noeud                      */
  /* ---------------------------------------------------- */
   FONCTION Nombre_noeud ( P ) : ENTIER
   SOIENT
       P UN ARB ;
      
   DEBUT
       SI P = NIL
           Nombre_noeud := 0 ;
          
       SINON
           Nombre_noeud := Nombre_noeud ( FG ( P ) ) + Nombre_noeud ( FD ( P ) ) + 1 ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                    Verifier_fusion                     */
  /* ---------------------------------------------------- */
   FONCTION Verifier_fusion ( P , N ) : BOOLEEN
   SOIENT
       P UN ARB ;
       N UN ENTIER ;
      
   DEBUT
       SI ( Nombre_noeud ( P ) = N ) ET ( Verifier_bst ( P , 0 , 10000 ) = VRAI )
           Verifier_fusion := VRAI ;
          
       SINON
           Verifier_fusion := FAUX ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                    Supprimer_arb                     */
  /* ---------------------------------------------------- */
   ACTION Supprimer_arb ( P )
   SOIENT
       P UN ARB ;
      
   DEBUT
       SI P <> NIL
           APPEL Supprimer_arb ( FG ( P ) ) ;
           APPEL Supprimer_arb ( FD ( P ) ) ;
           LIBERERNOEUD ( P ) ;
           P := NIL ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                   Suivant_inordre                    */
  /* ---------------------------------------------------- */
   FONCTION Suivant_inordre ( P ) : ARB
   SOIENT
       P UN ARB ;
       L UN BOOLEEN ;
      
   DEBUT
       L := VRAI ;
       SI FD ( P ) <> NIL
           P := FD ( P ) ;
           TANTQUE FG ( P ) <> NIL
               P := FG ( P ) ;
              
           FINTANTQUE ;
           Suivant_inordre := P ;
          
       SINON
           TANTQUE ( PERE ( P ) <> NIL ) ET ( L = VRAI )
               SI FG ( PERE ( P ) ) = P
                   Suivant_inordre := PERE ( P ) ;
                   L := FAUX ;
                  
               FSI ;
               SI L <> FAUX
                   P := PERE ( P ) ;
                  
               FSI ;
              
           FINTANTQUE ;
           SI L <> FAUX
               Suivant_inordre := NIL ;
              
           FSI ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                  Premier_postordre                   */
  /* ---------------------------------------------------- */
   FONCTION Premier_postordre ( P ) : POINTEUR VERS ARB
   SOIENT
       P : POINTEUR VERS ARB ;
      
   DEBUT
       SI P <> NIL
           TANTQUE ( FG ( P ) = NIL ) ET ( FD ( P ) <> NIL )
               P := FD ( P ) ;
              
           FINTANTQUE ;
           TANTQUE FG ( P ) <> NIL
               P := FG ( P ) ;
               TANTQUE ( FG ( P ) = NIL ) ET ( FD ( P ) <> NIL )
                   P := FD ( P ) ;
                  
               FINTANTQUE ;
              
           FINTANTQUE ;
          
       FSI ;
       Premier_postordre := P ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                  Suivant_postordre                   */
  /* ---------------------------------------------------- */
   FONCTION Suivant_postordre ( P ) : POINTEUR VERS ARB
   SOIENT
       P : POINTEUR VERS ARB ;
       L : BOOLEEN ;
      
   DEBUT
       L := VRAI ;
       SI ( PERE ( P ) = NIL )
           Suivant_postordre := NIL ;
           L := FAUX ;
          
       FSI ;
       SI L = VRAI
           ;
           SI ( P = FD ( PERE ( P ) ) ) OU ( FD ( PERE ( P ) ) = NIL )
               Suivant_postordre := PERE ( P ) ;
              
           SINON
               Suivant_postordre := Premier_postordre ( FD ( PERE ( P ) ) ) ;
              
           FSI ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                  Suivant_preordre                    */
  /* ---------------------------------------------------- */
   FONCTION Suivant_preordre ( P ) : ARB
   SOIENT
       P , Parent DES ARB ;
       L UN BOOLEEN ;
      
   DEBUT
       L := VRAI ;
       SI FG ( P ) <> NIL
           Suivant_preordre := FG ( P ) ;
          
       SINON
           SI FD ( P ) <> NIL
               Suivant_preordre := FD ( P ) ;
              
           SINON
               Parent := PERE ( P ) ;
               TANTQUE ( Parent <> NIL ) ET ( L = VRAI )
                   SI ( FG ( Parent ) = P ) ET ( FD ( Parent ) <> NIL )
                       Suivant_preordre := FD ( Parent ) ;
                       L := FAUX ;
                      
                   SINON
                       P := Parent ;
                       Parent := PERE ( P ) ;
                      
                   FSI ;
                  
               FINTANTQUE ;
               SI L = VRAI
                   Suivant_preordre := NIL ;
                  
               FSI ;
              
           FSI ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                      Option1                         */
  /* ---------------------------------------------------- */
   ACTION Option1 ( A1 , A2 , A3 , P , Q )
   SOIENT
       A1 , A2 , A3 , P , Q DES ARB ;
      
   DEBUT
       A3 := NIL ;
      /* Initialisation des pointeurs */
       P := A1 ;
       Q := A2 ;
       TANTQUE FG ( P ) <> NIL
           P := FG ( P ) ;
          
       FINTANTQUE ;
      /* Debut des parcours */
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_inordre ( P ) ;
              
           SINON
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_preordre ( Q ) ;
              
           FSI ;
          
       FINTANTQUE ;
       SI ( P = NIL ) ET ( Q <> NIL )
           TANTQUE Q <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_preordre ( Q ) ;
              
           FINTANTQUE ;
          
       FSI ;
       SI ( P <> NIL ) ET ( Q = NIL )
           TANTQUE P <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_inordre ( P ) ;
              
           FINTANTQUE ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                      Option2                         */
  /* ---------------------------------------------------- */
   ACTION Option2 ( A1 , A2 , A3 , P , Q )
   SOIENT
       A1 , A2 , A3 , P , Q DES ARB ;
      
   DEBUT
       A3 := NIL ;
      /* Initialisation des pointeurs */
       P := A1 ;
       Q := A2 ;
       TANTQUE FG ( P ) <> NIL
           P := FG ( P ) ;
          
       FINTANTQUE ;
       Q := Premier_postordre ( Q ) ;
      /* Debut des parcours */
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_inordre ( P ) ;
              
           SINON
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_postordre ( Q ) ;
              
           FSI ;
          
       FINTANTQUE ;
       SI ( P = NIL ) ET ( Q <> NIL )
           TANTQUE Q <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_postordre ( Q ) ;
              
           FINTANTQUE ;
          
       FSI ;
       SI ( P <> NIL ) ET ( Q = NIL )
           TANTQUE P <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_inordre ( P ) ;
              
           FINTANTQUE ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                      Option3                         */
  /* ---------------------------------------------------- */
   ACTION Option3 ( A1 , A2 , A3 , P , Q )
   SOIENT
       A1 , A2 , A3 , P , Q DES ARB ;
      
   DEBUT
       A3 := NIL ;
      /* Initialisation des pointeurs */
       P := A1 ;
       Q := A2 ;
      /* Debut des parcours */
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_preordre ( P ) ;
              
           SINON
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_preordre ( Q ) ;
              
           FSI ;
          
       FINTANTQUE ;
       SI ( P = NIL ) ET ( Q <> NIL )
           TANTQUE Q <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_preordre ( Q ) ;
              
           FINTANTQUE ;
          
       FSI ;
       SI ( P <> NIL ) ET ( Q = NIL )
           TANTQUE P <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_preordre ( P ) ;
              
           FINTANTQUE ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                      Option4                         */
  /* ---------------------------------------------------- */
   ACTION Option4 ( A1 , A2 , A3 , P , Q )
   SOIENT
       A1 , A2 , A3 , P , Q DES ARB ;
      
   DEBUT
       A3 := NIL ;
      /* Initialisation des pointeurs */
       P := A1 ;
       Q := A2 ;
       P := Premier_postordre ( P ) ;
       Q := Premier_postordre ( Q ) ;
      /* Debut des parcours */
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_postordre ( P ) ;
              
           SINON
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_postordre ( Q ) ;
              
           FSI ;
          
       FINTANTQUE ;
       SI ( P = NIL ) ET ( Q <> NIL )
           TANTQUE Q <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_postordre ( Q ) ;
              
           FINTANTQUE ;
          
       FSI ;
       SI ( P <> NIL ) ET ( Q = NIL )
           TANTQUE P <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_postordre ( P ) ;
              
           FINTANTQUE ;
          
       FSI ;
      
   FIN
  /* ---------------------------------------------------- */
  /*                      Option5                         */
  /* ---------------------------------------------------- */
   ACTION Option5 ( A1 , A2 , A3 , P , Q )
   SOIENT
       A1 , A2 , A3 , P , Q DES ARB ;
      
   DEBUT
       A3 := NIL ;
      /* Initialisation des pointeurs */
       P := A1 ;
       Q := A2 ;
       Q := Premier_postordre ( Q ) ;
      /* Debut des parcours */
       TANTQUE ( P <> NIL ) ET ( Q <> NIL )
           SI MIN ( INFO ( P ) , INFO ( Q ) ) = INFO ( P )
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_preordre ( P ) ;
              
           SINON
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_postordre ( Q ) ;
              
           FSI ;
          
       FINTANTQUE ;
       SI ( P = NIL ) ET ( Q <> NIL )
           TANTQUE Q <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( Q ) ) ;
               Q := Suivant_postordre ( Q ) ;
              
           FINTANTQUE ;
          
       FSI ;
       SI ( P <> NIL ) ET ( Q = NIL )
           TANTQUE P <> NIL
               APPEL Inserer_avec_double ( A3 , INFO ( P ) ) ;
               P := Suivant_preordre ( P ) ;
              
           FINTANTQUE ;
          
       FSI ;
      
   FIN
